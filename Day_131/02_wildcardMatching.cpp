// Question Link: https://leetcode.com/problems/wildcard-matching/

/*
44. Wildcard Matching

Given an input string (s) and a pattern (p), implement wildcard pattern matching with support for '?' and '*' where:

'?' Matches any single character.
'*' Matches any sequence of characters (including the empty sequence).
The matching should cover the entire input string (not partial).

Example 1:
Input: s = "aa", p = "a"
Output: false
Explanation: "a" does not match the entire string "aa".
Example 2:
Input: s = "aa", p = "*"
Output: true
Explanation: '*' matches any sequence.
Example 3:
Input: s = "cb", p = "?a"
Output: false
Explanation: '?' matches 'c', but the second letter is 'a', which does not match 'b'.
 
Constraints:
0 <= s.length, p.length <= 2000
s contains only lowercase English letters.
p contains only lowercase English letters, '?' or '*'.
*/



class Solution {
public:
    int solve(int i,int j,int &a,int &b,string &s,string &p,vector<vector<int>> &dp){
        if(i==a && j==b)return 1;
        else if(i==a){
            while(j<b && p[j]=='*')j++;
            return j==b;
        }
        else if(i != a && j == b)return 0;
        if(dp[i][j] != -1)return dp[i][j];
        bool c = false;
        while(j<b && p[j]=='*'){j++;c = true;}
        
        if(c)j--;
        if(p[j]=='?'){
            dp[i][j] = solve(i+1,j+1,a,b,s,p,dp);
        }else if(p[j]=='*'){
            dp[i][j] = solve(i+1,j,a,b,s,p,dp)||solve(i,j+1,a,b,s,p,dp);
        }else{
            if(s[i]==p[j]){
                dp[i][j] = solve(i+1,j+1,a,b,s,p,dp);
            }else{
                dp[i][j] = 0;
            }
        }
        return dp[i][j];
    }
    bool isMatch(string s, string p) {
        int a = s.length(),b= p.length();
        vector<vector<int>> dp(a,vector<int>(b,-1));
        return solve(0,0,a,b,s,p,dp);
    }
};
