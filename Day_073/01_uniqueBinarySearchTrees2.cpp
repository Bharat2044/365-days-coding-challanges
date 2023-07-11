// Question Link: https://www.interviewbit.com/problems/unique-binary-search-trees-ii/

/*
Unique Binary Search Trees II

Given an integer A, how many structurally unique BST’s (binary search trees) exist that can store values 1…A?

Input Format:
The first and the only argument of input contains the integer, A.

Output Format:
Return an integer, representing the answer asked in problem statement.

Constraints:
1 <= A <= 18

Example:
Input 1:
    A = 3
Output 1:
    5

Explanation 1:
   1         3     3      2      1
    \       /     /      / \      \
     3     2     1      1   3      2
    /     /       \                 \
   2     1         2                 3
*/



int Solution::numTrees(int A) {
    int dp[A+1]={0};

    dp[0]=1;
    dp[1]=1;
    dp[2]=2;

    for(int i=3;i<=A;i++) {
        for(int j=0;j<=i-1;j++)
            dp[i] += dp[j]*dp[i-j-1];
    }
    
    return dp[A];
}
