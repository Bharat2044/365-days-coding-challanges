// Question Link: https://www.interviewbit.com/problems/black-shapes/

/*
Black Shapes

Given N x M character matrix A of O's and X's, where O = white, X = black.

Return the number of black shapes. A black shape consists of one or more adjacent X's (diagonals not included)

Input Format:
    The First and only argument is a N x M character matrix.
    
Output Format:
    Return a single integer denoting number of black shapes.
    
Constraints:
    1 <= N,M <= 1000
    A[i][j] = 'X' or 'O'
    
Example:
Input 1:
    A = [ OOOXOOO
          OOXXOXO
          OXOOOXO  ]
Output 1:
    3
Explanation:
    3 shapes are  :
    (i)    X
         X X
    (ii)
          X
    (iii)
          X
          X
Note: we are looking for connected shapes here.

XXX
XXX
XXX
is just one single connected black shape.
*/



void dfs(int r,int c,vector<string> &A,vector<vector<int>> &vis){
    int n=A.size();
    int m=A[0].size();
    int delr[]={1,0,-1,0};
    int delc[]={0,-1,0,1};
    for(int i=0;i<4;i++){
        int newr=r+delr[i];
        int newc=c+delc[i];
        if(newr>=0 && newc>=0 && newr<n && newc<m){
            if(!vis[newr][newc] && A[newr][newc]=='X'){
                vis[newr][newc]=1;
                dfs(newr,newc,A,vis);
            }
        }
    }
}

int Solution::black(vector<string> &A) {
    int n=A.size();
    int m=A[0].size();
    vector<vector<int>> vis(n,vector<int>(m,0));
    int cnt=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(A[i][j]=='X' && !vis[i][j]){
                cnt++;
                vis[i][j]=1;
                dfs(i,j,A,vis);
            }
        }
    }
    return cnt;
}
