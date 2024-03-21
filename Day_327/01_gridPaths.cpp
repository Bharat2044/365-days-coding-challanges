// Question Link: https://www.interviewbit.com/problems/grid-paths/

/*
Grid Paths

Problem Description:
You are given a 2D grid A of size N x N. Rows are numbered from top to bottom from 0 to N - 1 and the columns are numbered from left to right from 0 to N - 1.
From a cell, you can either move left, right, up, and down. You cannot move outside of the grid. Some cells are blocked. A cell is blocked if A[i][j] is 0, otherwise A[i][j] denotes the value at ith row and jth column.
Consider every path from (0, 0) to (N-1, N-1) which visits each unblocked cell exactly once. The cost of a path is the sum of absolute values of adjacent cells of the path. Formally, if the values of the path are B1, B2, ...,, Br, the cost of the path is ∑ | Bi - Bi-1 | for i from 2 to r.
Find the sum of the cost of all such paths.

Note : Interpreter languages like Python may not work. Please try it in languages like C/ C++/ Java.

Problem Constraints:
2 <= N <= 7
0 <= A[i][j] <= 100
0 < A[0][0], A[N-1][N-1] <= 100

Input Format:
The first and only argument contains an 2D array A of size N x N.

Output Format:
Return the sum of cost of all paths from (0, 0) to (N-1, N-1) which visits each unblocked cell exactly once.

Example Input:
Input 1:
  A : 
  [
    [5, 2]
    [0, 7]
  ]
Input 2:
  A : 
  [
    [79, 19, 59]
    [45, 89, 63]
    [79, 81, 37]
  ]

Example Output:
Output 1:
  8
Output 2:
  472

Example Explanation:
Explanation 1:
  Valid path is [5, 2, 7]. Cost is |5-2| + |7-2| = 8 
Explanation 2:
  There are two valid paths-
  1. [79, 19, 59, 63, 89, 45, 79, 81, 37]
  Cost = 254
  2. [79, 45, 79, 81, 89, 19, 59, 63, 37]
  Cost = 218
*/



int n,vis[10][10],a[10][10],ans;
void f(int i, int j, int dir, int cnt, int sum){
    if(i==n-1 and j==n-1){
        if(cnt == n*n)
            ans+=sum;
        return;
    }
   
    if(dir==0){
        if((i-1<0 or vis[i-1][j]==1) and (j-1>=0 and !vis[i][j-1]) and (j+1<n and !vis[i][j+1])){
            return;
        }
    }
    else if(dir==1){
        if((j+1>=n or vis[i][j+1]==1) and (i-1>=0 and !vis[i-1][j]) and (i+1<n and !vis[i+1][j])){
            return;
        }
    }
    else if(dir==2){
        if((i+1>=n or vis[i+1][j]==1) and (j-1>=0 and !vis[i][j-1]) and (j+1<n and !vis[i][j+1])){
            return;
        }
    }
    else{
        if((j-1<0 or vis[i][j-1]==1) and (i-1>=0 and !vis[i-1][j]) and (i+1<n and !vis[i+1][j])){
            return;
        }
    }
   
    if(i-1>=0 and !vis[i-1][j]){
        vis[i-1][j] = 1;
        f(i-1, j, 0, cnt+1, sum + abs(a[i-1][j]-a[i][j]));
        vis[i-1][j] = 0;
    }
    if(j+1<n and !vis[i][j+1]){
        vis[i][j+1] = 1;
        f(i, j+1, 1, cnt+1, sum + abs(a[i][j+1]-a[i][j]));
        vis[i][j+1] = 0;
    }
    if(i+1<n and !vis[i+1][j]){
        vis[i+1][j] = 1;
        f(i+1, j, 2, cnt+1, sum + abs(a[i+1][j]-a[i][j]));
        vis[i+1][j] = 0;
    }
    if(j-1>=0 and !vis[i][j-1]){
        vis[i][j-1] = 1;
        f(i, j-1, 3, cnt+1,sum + abs(a[i][j-1]-a[i][j]));
        vis[i][j-1] = 0;
    }
}
int Solution::solve(vector<vector<int> > &A) {
    n=A.size();
    int cnt=0;
    ans=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            a[i][j] = A[i][j];
            if(a[i][j]) vis[i][j] = 0;
            else vis[i][j] = 1;
            cnt += vis[i][j];
            vis[i][j] *= 2;
        }
    }
    vis[0][0]=1;
    f(0,0,1,cnt+1,0);
    vis[0][0]=0;
    return ans;
}
