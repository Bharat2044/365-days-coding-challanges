// Question Link: https://www.interviewbit.com/problems/ways-to-color-a-3xn-board/

/*
Ways to color a 3xN Board

Given a 3 x A board,  find the number of ways to color it using at most 4 colors such that no 2 adjacent boxes have same color.

Diagonal neighbors are not treated as adjacent boxes.
Return the ways modulo 109 + 7 as the answer grows quickly.

Input Format:
The first and the only argument contains an integer, A.

Output Format:
Return an integer representing the number of ways to color the board.

Constraints:
1 <= A < 100000

Examples:
Input 1:
    A = 1
Output 1:
    36
Input 2:
    A = 2
Output 2:
    588
*/


using ll = long long;
int Solution::solve(int A) {
    vector<vector<int> > valid;
    ll mod = 1e9 + 7;
    ll dp[A + 1][4][4][4];
    for(int j = 0; j <= 3; j ++){
        for(int k = 0; k <= 3; k ++){
            if(k == j)
                continue;
            for(int l = 0; l <= 3; l ++){
                if(l == k)
                    continue;
                valid.push_back(vector<int>{j, k, l});
                dp[1][j][k][l] = 1;
            }
        }
    }
    
    for(int i = 2; i <= A; i ++){
        for(auto &v1: valid){
            dp[i][v1[0]][v1[1]][v1[2]] = 0;
            for(auto &v2: valid){
                if((v1[0] == v2[0]) || (v1[1] == v2[1]) || (v1[2] == v2[2]))
                    continue;
                dp[i][v1[0]][v1[1]][v1[2]] += dp[i - 1][v2[0]][v2[1]][v2[2]];
                dp[i][v1[0]][v1[1]][v1[2]] %= mod;
            }
        }
    }   
    ll ans = 0;
    for(auto &v1: valid){
        ans += dp[A][v1[0]][v1[1]][v1[2]];
        ans %= mod;
    }
    return ans;
}
