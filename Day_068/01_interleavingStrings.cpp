// Question Link: https://www.interviewbit.com/problems/interleaving-strings/

/*
Interleaving Strings

Given A, B, C, find whether C is formed by the interleaving of A and B.

Input Format:*
The first argument of input contains a string, A.
The second argument of input contains a string, B.
The third argument of input contains a string, C.

Output Format:
Return an integer, 0 or 1:
    => 0 : False
    => 1 : True
    
Constraints:
1 <= length(A), length(B), length(C) <= 150

Examples:
Input 1:
    A = "aabcc"
    B = "dbbca"
    C = "aadbbcbcac"
Output 1:
    1    
Explanation 1:
    "aa" (from A) + "dbbc" (from B) + "bc" (from A) + "a" (from B) + "c" (from A)

Input 2:
    A = "aabcc"
    B = "dbbca"
    C = "aadbbbaccc"
Output 2:
    0
Explanation 2:
    It is not possible to get C by interleaving A and B.
*/



int dp[151][151][151];
bool solve(string &A, string &B, string &C, int m, int n, int p){
    if(p != m + n)  
        return 0;

    if(m == 0) 
        return B.substr(0, n) == C.substr(0, p);
    else if(n == 0)
        return A.substr(0, m) == C.substr(0, p);

    if(dp[m][n][p] != -1)   
        return dp[m][n][p];    

    if(A[m - 1] == C[p - 1] && B[n - 1] == C[p - 1])
        return dp[m][n][p] = solve(A, B, C, m - 1, n, p - 1) || solve(A, B, C, m, n - 1, p - 1);
    else if(A[m - 1] == C[p - 1])
        return dp[m][n][p] = solve(A, B, C, m - 1, n, p - 1);
    else if(B[n - 1] == C[p - 1])
        return dp[m][n][p] = solve(A, B, C, m, n - 1, p - 1);
    else
        return dp[m][n][p] = 0;
}


int Solution::isInterleave(string A, string B, string C) {
    int m = A.size(), n = B.size(), p = C.size();

    for(int i = 0; i <= 150; i++){
        for(int j = 0; j <= 150; j++){
            for(int k = 0; k <= 150; k++)
                dp[i][j][k] = -1;
        }
    }

    return solve(A, B, C, m, n, p);
}
