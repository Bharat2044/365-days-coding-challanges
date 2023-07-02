// Question Link: https://www.interviewbit.com/problems/min-sum-path-in-matrix/

/*
Min Sum Path in Matrix

Problem Description:
Given a 2D integer array A of size M x N, you need to find a path from top left to bottom right which minimizes the sum of all numbers along its path.

NOTE: You can only move either down or right at any point in time. 

Input Format:
First and only argument is an 2D integer array A of size M x N.

Output Format:
Return a single integer denoting the minimum sum of a path from cell (1, 1) to cell (M, N).

Example Input
Input 1:
 A = [  [1, 3, 2]
        [4, 3, 1]
        [5, 6, 1]
     ]

Example Output:
Output 1:
 8

Example Explanation:
Explanation 1:
 The path is 1 -> 3 -> 2 -> 1 -> 1
 So ( 1 + 3 + 2 + 1 + 1) = 8
 */



int solve(int row,int column,vector<vector<int>>&arr,vector<vector<int>>&dp){
        if (row==0 && column==0){
            return arr[0][0];
        }
        if (row<0 || column <0){
            return 10e6;
        }
        if (dp[row][column]!=-1){
            return dp[row][column];
        }
        int x=solve(row-1,column,arr,dp);
        if (x!=10e6);
        int up = arr[row][column]+x;
        int y=solve(row,column-1,arr,dp);
        if (y!=10e6);
        int left=arr[row][column]+y;
        return dp[row][column]=min(up,left);

    }
int Solution::minPathSum(vector<vector<int> > &grid) {
      int n=grid.size();
      int m=grid[0].size();
      vector<vector<int>>dp(n,vector<int>(m,-1));
  
      return solve(n-1,m-1,grid,dp);
}
