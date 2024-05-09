// Question Link: https://www.interviewbit.com/problems/subset-sum-problem/

/*
Subset Sum Problem!
 
Problem Description:
Given an integer array A  of size N.
You are also given an integer B, you need to find whether their exist a subset in A whose sum equal B.
If there exist a subset then return 1 else return 0.

Problem Constraints:
1 <= N <= 100
1 <= A[i] <= 100
1 <= B <= 105

Input Format:
First argument is an integer array A.
Second argument is an integer B.

Output Format:
Return 1 if there exist a subset with sum B else return 0.

Example Input:
Input 1:
 A = [3, 34, 4, 12, 5, 2]
 B = 9
Input 2:
 A = [3, 34, 4, 12, 5, 2]
 B = 30

Example Output:
Output 1:
 1
Output 2:
 0

Example Explanation:
Explanation 1:
 There is a subset (4, 5) with sum 9.
Explanation 2:
 There is no subset that add up to 30.
*/


bool top_down_dp(vector<int> &nums, int sum, int index, signed char dp[][100005]) // returns if the sum is possible considering till 'index' elements
{
    if (sum == 0)
        return true;
    if (index < 0)
        return false;
    if (dp[index][sum] != -1)
        return dp[index][sum];

    bool ans = false;
    // choose the index
    if (sum - nums[index] >= 0)
        ans |= top_down_dp(nums, sum - nums[index], index - 1, dp);

    // didn't choose the index
    ans |= top_down_dp(nums, sum, index - 1, dp);

    return dp[index][sum] = ans;
}

int Solution::solve(vector<int> &A, int B)
{
    signed char dp[105][100005];
    memset(dp, -1, sizeof(dp));
    return top_down_dp(A, B, A.size() - 1, dp);
}
