// Question Link: https://www.interviewbit.com/problems/regular-expression-ii/

/*
Regular Expression II

Problem Description:
Implement regular expression matching with support for '.' and '*'.
'.' Matches any single character. 
'*' Matches zero or more of the preceding element.

The matching should cover the entire input string (not partial).

Return 0 / 1 ( 0 for false, 1 for true ) for this problem

Problem Constraints:
1 <= |A| <= 5 * 103
1 <= |B| <= 5 * 103


Input Format:
The first argument is a string A.
The second argument is a string A.

Output Format:
Return an integer, 0 / 1 ( 0 for false, 1 for true ) for this problem

Example Input:
isMatch("aa","a") → 0
isMatch("aa","aa") → 1
isMatch("aaa","aa") → 0
isMatch("aa", "a*") → 1
isMatch("aa", ".*") → 1
isMatch("ab", ".*") → 1
isMatch("aab", "c*a*b") → 1
*/





int Solution::isMatch(const string A, const string B) {
    int m = A.size();
    int n = B.size();
    
    vector<vector<int>> dp(m+1, vector<int>(n+1, 0));
    dp[0][0] = 1;
    
    for(int i = 1; i <= m; i++){
        dp[i][0] = 0;
    }
    
    for(int j = 1; j <= n; j++){
        int flag = 1;
        if(B[j-1] != '*'){
            flag = 0;
        }
        //ALternating star and char
        else{
            for(int k = 1; k < j; k++){
                if(B[k-1] != '*' && B[k] != '*')
                {
                    flag = 0;
                    break;
                }
            }
        }
        dp[0][j] = flag;
    }

    for(int i = 1; i <= m; i++){
        for(int j = 1; j <= n; j++){
            
            if((A[i-1] == B[j-1]) || (B[j-1] == '.'))
                dp[i][j] = dp[i-1][j-1];            
            else if((B[j-1]) == '*')
                dp[i][j] = ( dp[i][j-2] ) | ( (j > 1 && (A[i-1] == B[j-2] || B[j-2] == '.')) ? dp[i-1][j] : 0);
            else 
                dp[i][j] = 0;
        }
    }
    
    return dp[m][n];
}
