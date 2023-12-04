// Question Link: https://www.interviewbit.com/problems/equal-average-partition/

/*
Equal Average Partition

Problem Description:
Given an array A with non negative numbers, divide the array into two parts such that the average of both the parts is equal.

Return both parts (If exist). If there is no solution. return an empty list.

NOTE:
If a solution exists, you should return a list of exactly 2 lists of integers A and B which follow the following condition :
numElements in A <= numElements in B
If numElements in A = numElements in B, then A is lexicographically smaller than B ( Lexicographical Order )
If multiple solutions exist, return the solution where length(A) is minimum. If there is still a tie, return the one where A is lexicographically smallest.

The array will contain only non-negative numbers.

Problem Constraints:
1 <= |A| <= 100
0 <= Ai <= 100
0 <= Σ(Ai) <= 5000

Input Format:
First and only argument is an integer array A.

Output Format:
Return 2D array consisting of two rows where each row denoted a partition.

Example Input:
Input 1:
A = [1 7 15 29 11 9]

Example Output:
Output 1:
[9 15] [1 7 11 29]

Example Explanation:
Explanation 1:
The average of part is (15+9)/2 = 12, average of second part elements is (1 + 7 + 11 + 29) / 4 = 12
*/



bool findSubset(int index, int count, int targetSum, vector<int> &nums, vector<int> &subset, vector<vector<vector<int>>>& memo)
{
    int n = nums.size();

    // Base cases
    if (count == 0 && targetSum == 0)
        return true; // Found a valid subset with desired count and sum
    else if (count == 0 || index >= n)
        return false; // Reached end of array or count reached 0, not a valid subset

    if (memo[index][count][targetSum] != -1)
        return memo[index][count][targetSum]; // Return the result from memoization table

    if (targetSum >= nums[index])
    {
        subset.push_back(nums[index]); // Include the current element
        bool isValidSubset = findSubset(index + 1, count - 1, targetSum - nums[index], nums, subset, memo);
        if (isValidSubset)
            return memo[index][count][targetSum] = true; // Valid subset found, store in memoization table
        subset.pop_back(); // Backtrack: Exclude the current element
    }
    
    return memo[index][count][targetSum] = findSubset(index + 1, count, targetSum, nums, subset, memo); // Move to the next element
}

vector<vector<int>> Solution::avgset(vector<int> &nums)
{
    int totalSum = 0;
    sort(nums.begin(), nums.end());
    int n = nums.size();

    for (int i = 0; i < n; i++)
    {
        totalSum += nums[i]; // Calculate the sum of all elements
    }

    vector<vector<int>> result;
    vector<vector<vector<int>>> memo(n, vector<vector<int>>(n / 2 + 1, vector<int>(totalSum + 1, -1))); // Memoization table

    for (int subsetSize = 1; subsetSize <= n / 2; subsetSize++)
    {
        if ((subsetSize * totalSum) % n == 0)
        {
            int targetSum = (subsetSize * totalSum) / n; // Calculate the target sum for each subset
            vector<int> subset;
            if (findSubset(0, subsetSize, targetSum, nums, subset, memo)) // Call the helper function to find a valid subset
            {
                vector<int> remaining;
                int i = 0, j = 0;
                while (i < n && j < subset.size())
                {
                    if (nums[i] == subset[j])
                    {
                        i++;
                        j++;
                    }
                    else
                    {
                        remaining.push_back(nums[i]);
                        i++;
                    }
                }
                while (i < n)
                {
                    remaining.push_back(nums[i]);
                    i++;
                }

                result.push_back(subset); // Add the found subset to the result
                result.push_back(remaining); // Add the remaining array to the result
                return result; // Return the result
            }
        }
    }
    return result; // If no solution found, return empty result
}
