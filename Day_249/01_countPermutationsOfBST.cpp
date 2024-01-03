// Question Link: https://www.interviewbit.com/problems/count-permutations-of-bst/

/*
Count Permutations of BST

You are given two positive integers A and B. For all permutations of [1, 2, …, A], we create a BST. Count how many of these have height B.

Notes:
Values of a permutation are sequentially inserted into the BST by general rules i.e in increasing order of indices.
Height of BST is maximum number of edges between root and a leaf.
Return answer modulo 109 + 7.
Expected time complexity is worst case O(N4).
1 ≤ N ≤ 50

For example,
A = 3, B = 1
Two permutations [2, 1, 3] and [2, 3, 1] generate a BST of height 1.
In both cases the BST formed is

    2
   / \
  1   3  

Another example,
A = 3, B = 2
Return 4.
*/


int Solution::cntPermBST(int A, int B) {
    if(A<=B) return 0;
    int N = (int) (1e9 + 7);
    vector<vector<long long>> dp(A+1, vector<long long> (B+2, 0));
    vector<vector<long long>> C(A+1, vector<long long> (A+1, 0));
   
     for(int n = 0; n <= A; n ++) {
            C[n][0] = 1;
            C[n][n] = 1;
        }
        for(int n = 1; n <= A; n ++) {
            for(int r = 1; r < n; r ++) {
                C[n][r] = (C[n - 1][r - 1] + C[n - 1][r])%N;
            }
        }
   
    dp[1][0] = 1;
    for(int i = 0;i<=B;i++) dp[0][i] = 1;
   
    for(int i = 1;i<=A;i++)
    {
        for(int j = 1;j<=B;j++)
        {
           long long temp = dp[i][j-1];
           if(j<=i-1){
           for(int k = 0;k<i;k++)
           {
               if(i-1-k>=0) temp=((temp%N) + (((dp[k][j-1])%N*(dp[i-1-k][j-1])%N)%N*C[i-1][k])%N)%N;
           }
           if(j>=2) temp=((temp%N) - (dp[i][j-1]%N))%N;
           }
           dp[i][j] = temp;
        }
    }
    int k = ((dp[A][B]%N)-(dp[A][B-1]%N))%N;
    if(k<0) k+=N;
    return k;
}


