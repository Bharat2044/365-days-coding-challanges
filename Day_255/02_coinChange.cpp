// Question Link: https://leetcode.com/problems/coin-change/

/*
322. Coin Change

You are given an integer array coins representing coins of different denominations and an integer amount representing a total amount of money.
Return the fewest number of coins that you need to make up that amount. If that amount of money cannot be made up by any combination of the coins, return -1.
You may assume that you have an infinite number of each kind of coin.

Example 1:
Input: coins = [1,2,5], amount = 11
Output: 3
Explanation: 11 = 5 + 5 + 1
Example 2:
Input: coins = [2], amount = 3
Output: -1
Example 3:
Input: coins = [1], amount = 0
Output: 0
 
Constraints:
1 <= coins.length <= 12
1 <= coins[i] <= 231 - 1
0 <= amount <= 104
*/



class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();

        int dp[n+1][amount+1];
        //initialization
        for (int i = 0 ; i < n+1 ; i++){
            dp[i][0] = 0 ; 
        }
        for (int i = 1 ; i < amount+1 ; i++){
            dp[0][i] = INT_MAX-1;
        }
        //Processing 
        for (int i = 1 ; i < n+1 ; i++){
            for(int j = 1 ; j < amount+1 ; j++){
                if (coins[i-1] <= j){
                    dp[i][j] = min(1 + dp[i][j-coins[i-1]] , dp[i-1][j]);
                    //(minimum of we either choose or dont choose)
                }
                else{
                    dp[i][j] = dp[i-1][j];
                    //we cannot choose
                }
            }
        }
        if (dp[n][amount] == INT_MAX -1 ){
            return -1;//we cannot create required
        }
        return dp[n][amount];
    }
};
