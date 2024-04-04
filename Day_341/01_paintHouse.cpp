// Question Link: https://www.interviewbit.com/problems/paint-house/

/*
Paint House!

Problem Description:
There are a row of N houses, each house can be painted with one of the three colors: red, blue or green.
The cost of painting each house with a certain color is different. You have to paint all the houses such that no two adjacent houses have the same color.
The cost of painting each house with a certain color is represented by a N x 3 cost matrix A.

For example, A[0][0] is the cost of painting house 0 with color red; A[1][2] is the cost of painting house 1 with color green, and so on.
Find the minimum total cost to paint all houses.

Problem Constraints:
1 <= N <= 10^5
1 <= A[i][j] <= 10^3

Input Format:
First and only argument is an 2D integer matrix A of size N x 3 denoting the cost to paint the houses.

Output Format:
Return an integer denoting the minimum total cost to paint all houses.

Example Input:
Input 1:
 A = [  [1, 2, 3]
        [10, 11, 12]
     ]

Example Output:
Output 1:
 12

Example Explanation:
Explanation 1:
 Paint house 1 with red and house 2 with green i.e A[0][0] + A[1][1] = 1 + 11 = 12
*/



int solver(int i, int r, int g, int b, vector<vector<int>> &A, vector<vector<vector<vector<int>>>> &dp) {
    if (i >= A.size()) {
        return 0;
    }
    
    if(dp[i][r][g][b] != -1){
        return dp[i][r][g][b];
    }

    int maxi = INT_MAX;
    if (r == 1) {
        maxi = min(maxi, min(A[i][0] + solver(i + 1, 0, 1, 0, A, dp), A[i][0] + solver(i + 1, 0, 0, 1, A, dp)));
    }
    
    if (b == 1) {
        maxi = min(maxi, min(A[i][1] + solver(i + 1, 0, 1, 0, A, dp), A[i][1] + solver(i + 1, 1, 0, 0, A, dp)));
    }
    
    if (g == 1) {
        maxi = min(maxi, min(A[i][2] + solver(i + 1, 0, 0, 1, A, dp), A[i][2] + solver(i + 1, 1, 0, 0, A, dp)));
    }
    
    return dp[i][r][g][b] = maxi;
}

int Solution::solve(vector<vector<int>> &A) {
    vector<vector<vector<vector<int>>>> dp(A.size(), vector<vector<vector<int>>>(2, vector<vector<int>>(2, vector<int>(2, -1))));

    return min(solver(0, 1, 0, 0, A,dp), min(solver(0, 0, 1, 0, A,dp), solver(0, 0, 0, 1, A,dp)));
}
