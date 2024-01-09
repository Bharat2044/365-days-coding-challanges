// Question Link: https://www.interviewbit.com/problems/maximize-matrix-xor/

/*
Maximize matrix XOR

Problem Description:
Robin buys an integer matrix A of size N x M.

His mother asked him to perform the following operation exactly once such that the bitwise XOR of the elements is maximized.

Select any row or column of the matrix and decrement each element of the selected row or coloumn by 1.
Return the maximum value of bitwise XOR of elements after performing the above operation.

Problem Constraints:
1 <= N x M <= 5 * 105
1 <= A[i][j] <= 109

Input Format:
First and only argument is a 2D array A of size N x M.

Output Format:
Return an integer denoting the maximum value of bitwise XOR of the matrix.

Example Input:
Input 1:
A = [
       [2, 3]
       [4, 5]
     ]
Input 2:
A = [
       [1, 2]
     ]

Example Output:
Output 1:
6
Output 2:
2

Example Explanation:
Explanation 1:
 Select 2nd row and decrement each element. So the new matrix is [[2, 3], [3, 4]].
 XOR of elements will be 6.
Explanation 2:
 Select 1st col and decrement the only element. New matrix is [[0, 2]].
 XOR of elements will be 2.
*/



int Solution::solve(vector<vector<int> > &A) {
    int n = A.size(), m = A[0].size(), x = 0;
    int r[n] = {0}, c[m] = {0};
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            x ^= A[i][j];
            r[i] ^= (A[i][j] ^ (A[i][j] - 1));
            c[j] ^= (A[i][j] ^ (A[i][j] - 1));    
        }
    }
    int ans = 0;
    for(int i = 0; i < n; i++)
        ans = max(ans, x ^ r[i]);
    for(int i = 0; i < m; i++)
        ans = max(ans, x ^ c[i]);
    return ans;
}
