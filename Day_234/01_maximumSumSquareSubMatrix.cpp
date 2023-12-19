// Question Link: https://www.interviewbit.com/problems/maximum-sum-square-submatrix/

/*
Maximum Sum Square SubMatrix

Problem Description:
Given a 2D integer matrix A of size N x N find a B x B submatrix where B<= N and B>= 1, such that sum of all the elements in submatrix is maximum.

Problem Constraints:
1 <= N <= 103.
1 <= B <= N 
-102 <= A[i][j] <= 102.

Input Format:
First arguement is an 2D integer matrix A.
Second argument is an integer B.

Output Format:
Return a single integer denoting the maximum sum of submatrix of size B x B.

Example Input:
Input 1:
 A = [
        [1, 1, 1, 1, 1]
        [2, 2, 2, 2, 2]
        [3, 8, 6, 7, 3]
        [4, 4, 4, 4, 4]
        [5, 5, 5, 5, 5]
     ]
 B = 3
Input 2:
 A = [
        [2, 2]
        [2, 2]
    ]
  B = 2

Example Output:
Output 1:
 48
Output 2:
 8

Example Explanation:
Explanation 1:
 Maximum sum 3 x 3 matrix is
    8 6 7
    4 4 4
    5 5 5
    Sum = 48
Explanation 2:
 Maximum sum 2 x 2 matrix is
  2 2
  2 2
  Sum = 8
*/



int Solution::solve(vector<vector<int> > &A, int B) {
    int n=A.size();
    int dp[n-B+1][n];

    for(int col=0;col<n;col++) {
        int first=0;
        int sum=0;

        for(int i=0;i<B;i++)
            sum+=A[i][col];

        dp[0][col]=sum;

        for(int row=B;row<n;row++) {
            sum-=A[first++][col];
            sum+=A[row][col];
            dp[row-B+1][col]=sum;
        }       
    }

    int maxsum=INT_MIN;

    for(int i=0;i<n-B+1;i++) {
        int first=0;
        int sum=0;

        for(int col=0;col<B;col++)
            sum+=dp[i][col];            

        if(maxsum<sum)
            maxsum=sum;         

        for(int col=B;col<n;col++) {
            sum-=dp[i][first++];
            sum+=dp[i][col];

            if(maxsum<sum)
                maxsum=sum; 
        }
    }

    return maxsum;
}


