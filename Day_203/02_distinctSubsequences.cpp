// Question Link: https://leetcode.com/problems/distinct-subsequences/

/*
115. Distinct Subsequences

Given two strings s and t, return the number of distinct subsequences of s which equals t.

The test cases are generated so that the answer fits on a 32-bit signed integer.

Example 1:
Input: s = "rabbbit", t = "rabbit"
Output: 3
Explanation:
As shown below, there are 3 ways you can generate "rabbit" from s.
rabbbit
rabbbit
rabbbit

Example 2:
Input: s = "babgbag", t = "bag"
Output: 5
Explanation:
As shown below, there are 5 ways you can generate "bag" from s.
babgbag
babgbag
babgbag
babgbag
babgbag
 
Constraints:
1 <= s.length, t.length <= 1000
s and t consist of English letters.
*/



class Solution {
public:
    int numDistinct(string s, string t) {
        int m = s.size(), n = t.size(), mod = 1e9+7;
        if(m < n) 
            return 0;

        vector<vector<int>> dp(m, vector<int>(n, 0));
        dp[0][0] = s[0]==t[0];

        for(int i = 1; i < m; i++) {
            if(s[i] == t[0]) dp[i][0] = (dp[i-1][0]%mod + 1)%mod;
            else dp[i][0] = dp[i-1][0];
        }
        
        for(int i = 1; i < m; i++) {
            for(int j = 1; j < n; j++) {
                if(s[i] == t[j]) dp[i][j] = (dp[i-1][j]%mod + dp[i-1][j-1]%mod)%mod;
                else dp[i][j] = dp[i-1][j];
            }
        }

        return dp[m-1][n-1];
    }
};
