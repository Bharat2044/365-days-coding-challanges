// Question Link: https://www.interviewbit.com/problems/merge-elements/

/*
Merge elements

Problem Description:
Given an integer array A of size N. You have to merge all the elements of the array into one with the minimum possible cost.

The rule for merging is as follows:
Choose any two adjacent elements of the array with values say X and Y and merge them into a single element with value (X + Y) paying a total cost of (X + Y).
Return the minimum possible cost of merging all elements.

Problem Constraints:
1 <= N <= 200
1 <= A[i] <= 10^3

Input Format:
First and only argument is an integer array A of size N.

Output Format:
Return an integer denoting the minimum cost of merging all elements.

Example Input:
Input 1:
 A = [1, 3, 7]
Input 2:
 A = [1, 2, 3, 4]

Example Output:
Output 1:
 15
Output 2:
 19

Example Explanation:
Explanation 1:
 All possible ways of merging:
 a) {1, 3, 7} (cost = 0) -> {4, 7} (cost = 4) -> {11} (cost = 4+11 = 15)
 b) {1, 3, 7} (cost = 0) -> {1, 10} (cost = 10) -> {11} (cost = 10+11 = 21)
 Thus, ans = 15
*/



int f(int i,int j,vector<int>&A,vector<int>&pref,vector<vector<int>>&dp){
    if(i==j)return 0;
    if(i+1==j)return A[i]+A[j];
    if(dp[i][j]!=-1)return dp[i][j];
    int ans=INT_MAX;
    for(int k=i;k<j;k++){
        ans=min(ans,pref[j+1]-pref[i]+f(i,k,A,pref,dp)+f(k+1,j,A,pref,dp));
    }
    return dp[i][j]= ans;
}

int Solution::solve(vector<int> &A) {
    int n=A.size();
    vector<int>pref(n+1,0);
    for(int i=1;i<=n;i++){
        pref[i]=pref[i-1]+A[i-1];
    }
    vector<vector<int>>dp(n,vector<int>(n,-1));
    return f(0,n-1,A,pref,dp);
}
