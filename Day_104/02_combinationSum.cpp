// Question Link: https://leetcode.com/problems/combination-sum/

/*
39. Combination Sum

Given an array of distinct integers candidates and a target integer target, return a list of all unique combinations of candidates where the chosen numbers sum to target. You may return the combinations in any order.

The same number may be chosen from candidates an unlimited number of times. Two combinations are unique if the 
frequency
 of at least one of the chosen numbers is different.

The test cases are generated such that the number of unique combinations that sum up to target is less than 150 combinations for the given input.

Example 1:
Input: candidates = [2,3,6,7], target = 7
Output: [[2,2,3],[7]]
Explanation:
2 and 3 are candidates, and 2 + 2 + 3 = 7. Note that 2 can be used multiple times.
7 is a candidate, and 7 = 7.
These are the only two combinations.
Example 2:
Input: candidates = [2,3,5], target = 8
Output: [[2,2,2,2],[2,3,3],[3,5]]
Example 3:
Input: candidates = [2], target = 1
Output: []
 
Constraints:
1 <= candidates.length <= 30
2 <= candidates[i] <= 40
All elements of candidates are distinct.
1 <= target <= 40
*/




class Solution {
public:
    vector<vector<int>> ans; // 2 D vector to store our answer
    void solve(int i, vector<int>& arr, vector<int>& temp, int target)
    {
        // if our target becomes zero at any point, then yess!! we wil find a possible combination
        if(target == 0) 
        {
            ans.push_back(temp); // include that combination in our answer
            return; // and then return, we are now not gonna explore more possiblity
        }
        
        // if at any point target becomes less than zero, then simply return, saying that no it is notpossible to our target combination sum
        if(target < 0)
            return;
        
        // if index crosses the last index, we will return saying that no more element is left to choosee
        if(i == arr.size())
            return;
        
        // As we dicussed for every element we have two choices whether to include in our answer or not include in our answer. 
		//so now, we are doing that
        
        // we are not taking the ith element,
        // so without decreasing sum we will move to next index because it will not contribute in making our sum
        solve(i + 1, arr, temp, target);
        
        // we are taking the ith element and not moving onto the next element because it may be possible that this element again contribute in making our sum.
        // but we decrease our target sum as we are consediring that this will help us in making our target sum
        
        temp.push_back(arr[i]); // including ith element
        solve(i, arr, temp, target - arr[i]); // decreasing sum,and call again function
        temp.pop_back(); // backtrack
        
    }
    vector<vector<int>> combinationSum(vector<int>& arr, int target) {
        ans.clear(); // clear global array, make to sure that no garbage value is present in it
        
        vector<int> temp; // temporary vector that tries all possible combination
        
        solve(0, arr, temp, target); // calling function, and see we start from index zero
        
        return ans; // finally return the answer array
    }
};
