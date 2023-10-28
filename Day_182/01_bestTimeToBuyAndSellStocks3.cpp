// Question Link: https://www.interviewbit.com/problems/best-time-to-buy-and-sell-stocks-iii/

/*
Best Time to Buy and Sell Stocks III

Problem Description:
Say you have an array, A, for which the ith element is the price of a given stock on day i.

Design an algorithm to find the maximum profit. You may complete at most 2 transactions.

Return the maximum possible profit.

Note: You may not engage in multiple transactions at the same time (ie, you must sell the stock before you buy again).

Problem Constraints:
1 <= length(A) <= 7e5
1 <= A[i] <= 1e7

Input Format:
The first and only argument is an integer array, A.

Output Format:
Return an integer, representing the maximum possible profit.

Example Input:
Input 1:
    A = [1, 2, 1, 2]
Input 2:
    A = [7, 2, 4, 8, 7]

Example Output:
Output 1:
    2
Output 2:
    6

Example Explanation:
Explanation 1: 
    Day 0 : Buy 
    Day 1 : Sell
    Day 2 : Buy
    Day 3 : Sell
Explanation 2:
    Day 1 : Buy
    Day 3 : Sell
*/




int f(int index,int buy, int cap, const vector<int> &A,vector<vector<vector<int>>> &dp) {

    if(index==A.size()) // U have exhausted the days of the transaction
        return 0;

    if(cap==0) // U have done 2 transactions so u cant do anymore
        return 0;

    if(dp[index][buy][cap]!=-1)
        return dp[index][buy][cap];

    int profit;

    //If we can allowed to buy then either we buy or we dont buy.
    if(buy)
        profit=max( -A[index]+f(index+1,0,cap,A,dp) , 0+f(index+1,1,cap,A,dp) );
    else
        profit=max( +A[index]+f(index+1,1,cap-1,A,dp), 0+f(index+1,0,cap,A,dp) );

    return dp[index][buy][cap]=profit;
}

int Solution::maxProfit(const vector<int> &A) {
    int n=A.size();

    vector<vector<int>> curr(2,vector<int>(3,0));
    vector<vector<int>> after(2,vector<int>(3,0));

    if(n==0||n==1)
        return 0;   

    int profit;

    for(int index=n-1;index>=0;index--) {
        for(int buy=0;buy<2;buy++) {
            
            for(int cap=1;cap<3;cap++) {
                //If we can allowed to buy then either we buy or we dont buy.
                if(buy)
                    profit=max( -A[index]+after[0][cap]  , 0+after[1][cap] );
                else // If we are allowed to sell then either we sell or we dont.
                    profit=max( +A[index]+after[1][cap-1], 0+after[0][cap] );
                    
                curr[buy][cap]=profit;
            }
        }

        after=curr;
    }    

    return after[1][2];
}


