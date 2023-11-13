// Question Link: https://leetcode.com/problems/coin-change-ii/

/*
518. Coin Change II

You are given an integer array coins representing coins of different denominations and an integer amount representing a total amount of money.

Return the number of combinations that make up that amount. If that amount of money cannot be made up by any combination of the coins, return 0.

You may assume that you have an infinite number of each kind of coin.

The answer is guaranteed to fit into a signed 32-bit integer.

Example 1:
Input: amount = 5, coins = [1,2,5]
Output: 4
Explanation: there are four ways to make up the amount:
5=5
5=2+2+1
5=2+1+1+1
5=1+1+1+1+1
Example 2:
Input: amount = 3, coins = [2]
Output: 0
Explanation: the amount of 3 cannot be made up just with coins of 2.
Example 3:
Input: amount = 10, coins = [10]
Output: 1
 
Constraints:
1 <= coins.length <= 300
1 <= coins[i] <= 5000
All the values of coins are unique.
0 <= amount <= 5000
*/



class Solution {
public:
int sol(int ind,int amount, vector<int>& coins,vector<vector<int>> &dp){
       if(ind==0){
           return (amount%coins[0]==0);
            } 
            
            if( dp[ind][amount]!=-1)return dp[ind][amount];

           int nottake=sol(ind-1,amount,coins,dp);
           int take=0;
           if(coins[ind]<=amount){
               take=sol(ind,amount-coins[ind],coins,dp);
           }
          
 return dp[ind][amount]=take+nottake;
}
    int change(int amount, vector<int>& coins) {
        int ind=coins.size();
        vector<vector<int>> dp(ind,vector<int>(amount+1,-1));
            return sol(ind-1,amount,coins,dp);
    }
};
