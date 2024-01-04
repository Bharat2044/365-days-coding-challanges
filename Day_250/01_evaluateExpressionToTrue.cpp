// Question Link: https://www.interviewbit.com/problems/evaluate-expression-to-true/

/*
Evaluate Expression To True

Given an expression, A, with operands and operators (OR , AND , XOR), in how many ways can you evaluate the expression to true, by grouping in different ways?
Operands are only true and false.
Return the number of ways to evaluate the expression modulo 103 + 3.

Input Format:
The first and the only argument of input will contain a string, A.
The string A, may contain these characters:
    '|' will represent or operator 
    '&' will represent and operator
    '^' will represent xor operator
    'T' will represent true operand
    'F' will false

Output:
Return an integer, representing the number of ways to evaluate the string.

Constraints:
1 <= length(A) <= 150

Example:
Input 1:
    A = "T|F"
Output 1:
    1
Explanation 1:
    The only way to evaluate the expression is:
        => (T|F) = T 
Input 2:
    A = "T^T^F"
Output 2:
    0
Explanation 2:
    There is no way to evaluate A to a true statement.
*/



int Solution::cnttrue(string A) {
    int mod = 1e3+3;
    int n = A.size();
    pair<int, int> dp[n][n];
    for(int i=0;i<n;i+=2) {
        if(A[i]=='T') dp[i][i] = {1, 0};
        else dp[i][i] = {0, 1};
    }
    for(int len=3;len<=n;len+=2) {
        for(int i=0;i<=n-len;i+=2) {
            int st=i; int end = i+len-1;
            int one=0, zero=0;
            for(int j=st+1;j<end;j+=2){
                pair<int, int> left = dp[st][j-1];
                pair<int, int> right = dp[j+1][end];
                if(A[j]=='|'){
                    one+=(left.first*right.first)%mod; one%=mod;
                    one+=(left.first*right.second)%mod; one%=mod;
                    one+=(left.second*right.first)%mod; one%=mod;
                    zero+=(left.second*right.second)%mod; zero%=mod;
                }
                if(A[j]=='&'){
                    one+=(left.first*right.first)%mod; one%=mod;
                    zero+=(left.first*right.second)%mod; zero%=mod;
                    zero+=(left.second*right.first)%mod; zero%=mod;
                    zero+=(left.second*right.second)%mod; zero%=mod;
                }
                if(A[j]=='^'){
                    one+=(left.first*right.second)%mod; one%=mod;
                    one+=(left.second*right.first)%mod; one%=mod;
                    zero+=(left.first*right.first)%mod; zero%=mod;
                    zero+=(left.second*right.second)%mod; zero%=mod;
                }
            }
            dp[st][end] = {one, zero};
        }
    }
    return dp[0][n-1].first;
}
