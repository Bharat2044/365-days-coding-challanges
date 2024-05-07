// Question Link: https://leetcode.com/problems/knight-dialer/

/*
935. Knight Dialer

The chess knight has a unique movement, it may move two squares vertically and one square horizontally, or two squares horizontally and one square vertically (with both forming the shape of an L). The possible movements of chess knight are shown in this diagram:
A chess knight can move as indicated in the chess diagram below:
We have a chess knight and a phone pad as shown below, the knight can only stand on a numeric cell (i.e. blue cell).

Given an integer n, return how many distinct phone numbers of length n we can dial.
You are allowed to place the knight on any numeric cell initially and then you should perform n - 1 jumps to dial a number of length n. All jumps should be valid knight jumps.
As the answer may be very large, return the answer modulo 109 + 7.

Example 1:
Input: n = 1
Output: 10
Explanation: We need to dial a number of length 1, so placing the knight over any numeric cell of the 10 cells is sufficient.
Example 2:
Input: n = 2
Output: 20
Explanation: All the valid number we can dial are [04, 06, 16, 18, 27, 29, 34, 38, 40, 43, 49, 60, 61, 67, 72, 76, 81, 83, 92, 94]
Example 3:
Input: n = 3131
Output: 136006598
Explanation: Please take care of the mod. 

Constraints:
1 <= n <= 5000
*/



const int mod=1e9+7;
vector<vector<int>> M={
    {0, 2, 2, 0},
    {1, 0, 0, 0},
    {1, 0, 0, 2},
    {0, 0, 1, 0}
};
vector<vector<int>> I={
    {1, 0, 0, 0},
    {0, 1, 0, 0},
    {0, 0, 1, 0},
    {0, 0, 0, 1}
};
vector<vector<int>> operator*(vector<vector<int>> A,vector<vector<int>> B)
{
    int n=A.size(), k1=A[0].size(), k2=B.size(), m=B[0].size();
    if (k1!=k2) return {};
    vector<vector<int>> C(n, vector<int>(m, 0));
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            #pragma unroll
            for(int k=0; k<k1; k++)
                C[i][j]=(C[i][j]+(long long)A[i][k]*B[k][j]%mod)%mod;
        }
    }
    return C;
}
vector<vector<int>> pow(vector<vector<int>> M, int n){
    if (n==0) return I;
    vector<vector<int>> A=(n&1)?M:I;
    return pow((M*M), n/2)*A;
}
class Solution {
public:
    int knightDialer(int n) {
        if (n==1) return 10;
        n--;
        vector<vector<int>> A=vector<vector<int>>({{1,1,1,1}})*
        pow(M, n)*vector<vector<int>>({{4}, {2}, {2}, {1}});
        
        return A[0][0];
    }
};
