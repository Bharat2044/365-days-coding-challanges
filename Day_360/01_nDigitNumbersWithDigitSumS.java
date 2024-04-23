// Question Link: https://www.interviewbit.com/problems/n-digit-numbers-with-digit-sum-s-/

/*
N digit numbers with digit sum S

Find out the number of N digit numbers, whose digits on being added equals to a given number S. Note that a valid number starts from digits 1-9 except the number 0 itself. i.e. leading zeroes are not allowed.

Since the answer can be large, output answer modulo 1000000007
N = 2, S = 4 
 Valid numbers are {22, 31, 13, 40} 
 Hence output 4.
*/



int mod = 1e9+7;

int dfs(int num, int n, int s,vector<vector<int>> &dp) {
    if (s == 0 && n==0)
        return 1;

    if (s < 0 || n<0)
        return 0;
        
    if(dp[n][s]!=-1)
    return dp[n][s];
    

    int ans = 0;
    for (int i = 0; i <= 9; i++) {
        ans = (ans%mod + dfs(i, n-1, s - i,dp)%mod) % mod;
    }

    return dp[n][s] = ans%mod;
}

int Solution::solve(int n, int s) {
    int ans = 0;
    
    vector<vector<int>> dp(n+1,vector<int> (s+1,-1));
    for (int i = 1; i <= 9; i++) {
        ans = (ans%mod + dfs(i, n-1, s - i,dp)%mod) % mod;
    }

    return ans;
}
