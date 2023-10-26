// Question Link: https://leetcode.com/problems/unique-binary-search-trees/

/*
96. Unique Binary Search Trees

Given an integer n, return the number of structurally unique BST's (binary search trees) which has exactly n nodes of unique values from 1 to n.

Example 1:
Input: n = 3
Output: 5
Example 2:
Input: n = 1
Output: 1
 
Constraints:
1 <= n <= 19
*/



class Solution {
public:
    int dp[20];
    int helper(int n){
        if(n == 0)
            return 1;
        if(dp[n] != -1)
            return dp[n];
        int ans = 0;
        for(int k = 1 ; k <= n ; k++)
            ans += helper(k - 1) * helper(n - k);
        return dp[n] = ans;
    }
    
    int numTrees(int n) {
        memset(dp, -1, sizeof(dp));
        return helper(n);
    }
};
