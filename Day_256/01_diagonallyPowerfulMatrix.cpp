// Question Link: https://www.interviewbit.com/problems/diagonally-powerful-matrix/

/*
Diagonally powerful Matrix

Problem Description:
Robin purchase an integer matrix A of size N x M.
He wants to make the matrix Diagonally powerful Matrix, but he can only use the below operation:
Select any element, multiply or divide it by 2. Take floor while dividing it by 2.
Matrix is called Diagonally powerful matrix if all diagonals starting from Top or Left and ending at Bottom or Right is Powerful.

A diagonal is powerful if bitwise AND of the elements in the diagonal is greater than 1.
Find and return the minimum number of operations required to convert the matrix into Diagonally powerful Matrix.

Problem Constraints:
1 <= N x M <= 104
1 <= A[i][j] <= 107

Input Format:
First and only argument is a 2D array A.

Output Format:
Return an integer denoting the minimum number of operations required to convert the matrix into Diagonally powerful Matrix.

Example Input:
Input 1:
 A = [
       [2, 2, 1]
       [10, 4, 1]
       [11, 3, 2] 
     ]
Input 2:
 A = [
       [1]
       [5]
     ]

Example Output:
Output 1:
 3
Output 2:
 1

Example Explanation:
Explanation 1:
 Three operations are required:
 Select all 1's and multiply by 2 and select 4 and divide it by 2.
Explanation 2:
 Select 1 and multiply by 2, since we need AND greater than 1.
*/



int cost(vector<int>& v){
    int ans = 1e9;
    for(int i = 1; i < 26; i++){
        int cur = 0;
        for(auto j : v){
            int temp = 1e9;
            for(int k = 0; k < 26; k++){
                if(j & (1 << k))
                    temp = min(temp, abs(i-k));
            }
            cur += temp;
        }
        ans = min(ans, cur);
    }
    return ans;
}
int Solution::solve(vector<vector<int> > &A) {
    int n = A.size(), m = A[0].size(), ans = 0;
    for(int i = 0; i < n; i++){
        vector<int> v;
        int r = i, c = 0;
        while(r < n and c < m)
            v.push_back(A[r++][c++]);
        ans += cost(v);
    }
    for(int i = 1; i < m; i++){
        vector<int> v;
        int r = 0, c = i;
        while(r < n and c < m)
            v.push_back(A[r++][c++]);
        ans += cost(v);
    }
    return ans;
}
