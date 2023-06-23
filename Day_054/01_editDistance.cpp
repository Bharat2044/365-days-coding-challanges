// Question Link: https://www.interviewbit.com/problems/edit-distance/

/*
Edit Distance

Given two strings A and B, find the minimum number of steps required to convert A to B. (each operation is counted as 1 step.)

You have the following 3 operations permitted on a word: 
Insert a character
Delete a character
Replace a character

Input Format:
The first argument of input contains a string, A.
The second argument of input contains a string, B.

Output Format:
Return an integer, representing the minimum number of steps required.

Constraints:
1 <= length(A), length(B) <= 450

Examples:
Input 1:
    A = "abad"
    B = "abac"
Output 1:
    1
Explanation 1:
    Operation 1: Replace d with c.
    
Input 2:
    A = "Anshuman"
    B = "Antihuman"
Output 2:
    2
Explanation 2:
    => Operation 1: Replace s with t.
    => Operation 2: Insert i.
*/




int dp[451][451];

int solve(string &A, string &B, int m, int n){
    for(int i = 0; i <= m; i++) 
        dp[i][0] = i;   // subjected to base conditons in recursive Solution

    for(int j = 0; j <= n; j++)  
        dp[0][j] = j;   // subjected to base conditons in recursive Solution

    for(int i = 1; i <= m; i++){
        for(int j = 1; j <= n; j++){
            if(A[i-1] == B[j-1])   // if both letters matches
                dp[i][j] = dp[i-1][j-1];    /// no operation
            else                // if letters dismatches
                dp[i][j] = 1 + min(min(dp[i-1][j-1], dp[i-1][j]), dp[i][j-1]); // get min of 3 possibilities(replace, delete, insert)
        }
    }    

    return dp[m][n];
}

int Solution::minDistance(string A, string B) {
    int m = A.size(), n = B.size();
    return solve(A, B, m, n);
}
