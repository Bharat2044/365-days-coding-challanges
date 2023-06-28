// Question Link: https://www.interviewbit.com/problems/unique-paths-in-a-grid/

/*
Unique Paths in a Grid

Given a grid of size m * n, lets assume you are starting at (1,1) and your goal is to reach (m,n). At any instance, if you are on (x,y), you can either go to (x, y + 1) or (x + 1, y).

Now consider if some obstacles are added to the grids. How many unique paths would there be?

An obstacle and empty space is marked as 1 and 0 respectively in the grid.

Example :
There is one obstacle in the middle of a 3x3 grid as illustrated below.

[
  [0,0,0],
  [0,1,0],
  [0,0,0]
]
The total number of unique paths is 2.

Note: m and n will be at most 100.
*/




int Solution::uniquePathsWithObstacles(vector<vector<int> > &A){
    int m = A.size();
    int n = A[0].size();
    
    vector<vector<int>> dp(m+1, vector<int>(n+1, 0));
    
    if(A[m-1][n-1] == 1)
        return 0;
        
    dp[m-1][n-1] = 1;
    
    for(int i=m-1; i>=0; i--){
        for(int j=n-1; j>=0; j--){
            
            if(!(i == m-1 && j == n-1) && A[i][j] != 1)
                dp[i][j] = dp[i+1][j]+dp[i][j+1];            
        }
    }
    
    return dp[0][0];
}
