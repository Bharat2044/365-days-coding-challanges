// Question Link: https://www.interviewbit.com/problems/kth-manhattan-distance-neighbourhood/

/*
Kth Manhattan Distance Neighbourhood

Given a matrix M of size nxm and an integer K, find the maximum element in the K manhattan distance neighbourhood for all elements in nxm matrix. 
In other words, for every element M[i][j] find the maximum element M[p][q] such that abs(i-p)+abs(j-q) <= K.

Note: Expected time complexity is O(N*N*K)

Constraints:
1 <= n <= 300
1 <= m <= 300
1 <= K <= 300
0 <= M[i][j] <= 1000

Example:
Input:
M  = [[1,2,4],[4,5,8]] , K = 2

Output:
ans = [[5,8,8],[8,8,8]]
*/



vector<vector<int> > Solution::solve(int A, vector<vector<int> > &B){
    vector<vector<int>> dp=B;
    for(int k=1;k<=A;k++)
    {
        vector<vector<int>> h(B.size(),vector<int>(B[0].size()));
        for(int i=0;i<B.size();i++)
        {
            for(int j=0;j<B[0].size();j++)
            {
                h[i][j]=dp[i][j];
                if(i>0)
                    h[i][j]=max(h[i][j],dp[i-1][j]);
                if(i<B.size()-1)
                    h[i][j]=max(h[i][j],dp[i+1][j]);
                if(j>0)
                    h[i][j]=max(h[i][j],dp[i][j-1]);
                if(j<B[0].size()-1)
                    h[i][j]=max(h[i][j],dp[i][j+1]);
            }
        }
        dp=h;
    }
    return dp;
}
