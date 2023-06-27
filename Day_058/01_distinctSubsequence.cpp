// Question Link: https://www.interviewbit.com/problems/distinct-subsequences/

/*
Distinct Subsequences

Given two sequences A, B, count number of unique ways in sequence A, to form a subsequence that is identical to the sequence B.

Subsequence : A subsequence of a string is a new string which is formed from the original string by deleting some (can be none) of the characters without disturbing the relative positions of the remaining characters. (ie, “ACE” is a subsequence of “ABCDE” while “AEC” is not).

Input Format:
The first argument of input contains a string, A.
The second argument of input contains a string, B.

Output Format:
Return an integer representing the answer as described in the problem statement.

Constraints:
1 <= length(A), length(B) <= 700
Example :

Input 1:
    A = "abc"
    B = "abc"
    
Output 1:
    1
    
Explanation 1:
    Both the strings are equal.
Input 2:
    A = "rabbbit" 
    B = "rabbit"
Output 2:
    3
Explanation 2:
    These are the possible removals of characters:
        => A = "ra_bbit" 
        => A = "rab_bit" 
        => A = "rabb_it"
        
    Note: "_" marks the removed character.
*/




int f(int i,int j, string &A, string &B, vector<vector<int>>&dp){
    if(j < 0) 
        return 1;
    if(i < 0) 
        return 0;
    
    if(dp[i][j] != -1) 
        return dp[i][j];
    int pick = 0;
    
    if(A[i] == B[j])
        pick = f(i-1, j-1, A, B, dp);
    
    int notpick = f(i-1, j, A, B, dp);
    
    return dp[i][j] = pick+notpick;
}

int Solution::numDistinct(string A, string B) {
    vector<vector<int>> dp(A.size(),vector<int>(B.size(),-1));
    
    return f(A.size()-1, B.size()-1, A, B, dp);
}
