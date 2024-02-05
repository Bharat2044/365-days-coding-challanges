// Question Link: https://www.interviewbit.com/problems/maximum-path-in-triangle/

/*
Maximum Path in Triangle

Problem Description:
Given a 2D integer array A of size  N * N   representing a triangle of numbers.
Find the maximum path sum from top to bottom. Each step you may move to adjacent numbers on the row below.

NOTE:
Adjacent cells to cell (i,j) are only (i+1,j) and (i+1,j+1)
Row i contains i integer and n-i zeroes for all i in [1,n] where zeroes represents empty cells.

Problem Constraints:
0 <= N <= 1000 
0 <= A[i][j] <= 1000 

Input Format:
First and only argument is an 2D integer array A of size N * N.

Output Format:
Return a single integer denoting the maximum path sum from top to bottom in the triangle.

Example Input:
Input 1:
A = [
        [3, 0, 0, 0]
        [7, 4, 0, 0]
        [2, 4, 6, 0]
        [8, 5, 9, 3]
     ]
Input 2:
A = [
        [8, 0, 0, 0]
        [4, 4, 0, 0]
        [2, 2, 6, 0]
        [1, 1, 1, 1]
     ]

Example Output:
Output 1:
23
Output 2:
19

Example Explanation:
Explanation 1:
Given triangle looks like:  3
                             7 4
                             2 4 6
                             8 5 9 3
        So max path is (3 + 7 + 4 + 9) = 23
Explanation 1:
Given triangle looks like:  8
                             4 4
                             2 2 6
                             1 1 1 1
        So max path is (8 + 4 + 6 + 1) = 19
*/


int f(int i,int j,vector<vector<int>>&A,vector<vector<int>>&dp){
    int n=A.size();
    if(i==n-1)return A[i][j];
    if(dp[i][j]!=-1)return dp[i][j];
    int op1=f(i+1,j,A,dp);
    int op2=f(i+1,j+1,A,dp);
    return dp[i][j]= max(op1,op2)+A[i][j];
}

int Solution::solve(vector<vector<int> > &A) {
    int n=A.size();//rows
    vector<vector<int>>dp(n,vector<int>(n,-1));
    return f(0,0,A,dp);
}
