// Question Link: https://www.interviewbit.com/problems/141/

/*
NQueens

The n-queens puzzle is the problem of placing n queens on an n×n chessboard such that no two queens attack each other.

N Queens: Example 1
Given an integer n, return all distinct solutions to the n-queens puzzle.
Each solution contains a distinct board configuration of the n-queens’ placement, where 'Q' and '.' both indicate a queen and an empty space respectively.

For example,
There exist two distinct solutions to the 4-queens puzzle:
[
 [".Q..",  // Solution 1
  "...Q",
  "Q...",
  "..Q."],

 ["..Q.",  // Solution 2
  "Q...",
  "...Q",
  ".Q.."]
]
*/



vector<string> convert(vector<vector<int>> &grid)
{
    vector<string> vec = {};
    for(int i=0;i<grid.size();i++)
    {
        string x = "";
        for(int j=0;j<grid.size();j++)
        {
            if(grid[i][j] == 1)
            x+='Q';
            else
            x+='.';
        }
        vec.push_back(x);
    }
    return vec;
}

bool isok(int r,int c,vector<vector<int>> &grid,int n)
{
    if(r<0||c<0||r>=n||c>=n)
    return false;
   
    if(grid[r][c] == 1)
    return false;
   
    for(int i=0;i<n;i++)
    {
        if(grid[r][i] == 1 || grid[i][c] == 1)
        return false;
    }
   
    int rr = r;
    int cc = c;
    while(rr>=0 && cc>=0)
    {
        if(grid[rr--][cc--]==1)
        return false;
    }
   
    rr=r;
    cc=c;
    while(rr>=0&&cc<n)
    {
        if(grid[rr--][cc++]==1)
        return false;
    }
   
    rr=r;
    cc=c;
    while(rr<n&&cc>=0)
    {
        if(grid[rr++][cc--]==1)
        return false;
    }
   
    rr=r;
    cc=c;
    while(rr<n&&cc<n)
    {
        if(grid[rr++][cc++]==1)
        return false;
    }
   
    return true;
}

void solve(int col, vector<vector<int>> &grid,int n,int qc,vector<vector<string>> &ans)
{
   
    if(col == n && qc==0)
    {
       
        ans.push_back(convert(grid));
        return;
    }
   
    for(int i=0;i<n;i++)
    {
        if(isok(i,col,grid,n))
        {
            grid[i][col] = 1;
            solve(col+1,grid,n,qc-1,ans);
            grid[i][col] = 0;
        }
    }
}

vector<vector<string> > Solution::solveNQueens(int n) {
   
    vector<vector<int>> grid(n,vector<int> (n,0));
    vector<vector<string>> ans;
    solve(0,grid,n,n,ans);
   
    return ans;
}
