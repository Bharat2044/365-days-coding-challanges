// Question Link: https://leetcode.com/problems/climbing-stairs/description/

/*
70. Climbing Stairs

You are climbing a staircase. It takes n steps to reach the top.

Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?


Example 1:
Input: n = 2
Output: 2
Explanation: There are two ways to climb to the top.
1. 1 step + 1 step
2. 2 steps
Example 2:
Input: n = 3
Output: 3
Explanation: There are three ways to climb to the top.
1. 1 step + 1 step + 1 step
2. 1 step + 2 steps
3. 2 steps + 1 step
 
Constraints:
1 <= n <= 45
*/




class Solution {
public:
    int climbStairs(int n) {
        // Approach - 3: TC = O(n), SC = O(1)
        if(n <= 3)
            return n;

        int a = 1, b = 2;

        for(int i=3; i<=n; i++) {
            int t = a+b;
            a = b;
            b = t;
        }

        return b;


        // Approach - 2: TC = O(n), SC = O(1)
        /*if(n <= 2)
            return n;
        
        vector<int> dp(n+1);
        
        dp[0] = 0;
        dp[1] = 1;
        dp[2] = 2;
        
        for(int i=3; i<=n; i++)
            dp[i] = dp[i-1]+dp[i-2];
        
        return dp[n];*/


        // Approach - 1: TC = O(2^n), SC = O(n)
        /*if(n == 1)
            return 1;
        if(n == 2)
            return 2;
        
        return climbStairs(n-1) + climbStairs(n-2);*/
    }
};
