// Question Link: https://www.interviewbit.com/problems/maximize-the-matrix/

/*
Maximize the Matrix

Problem Description:
Given a matrix A of size N x M. You want to maximize the minimum of the matrix A by performing the following operation B number of times.
Select any submatrix of size 1 x C and increase all elements by 2.
Return the minimum value of the matrix after performing the operation such that minimum of the matrix is maximized.

Problem Constraints:
1 <= N x M <= 2 * 10^5
-10^8 <= A[i][j] <= 10^8
1 <= B <= 10^9
1 <= C <= M

Input Format:
First argument is a 2D array A of size N x M.
Second argument is an integer B.
Third argument is an integer C.

Output Format:
Return an integer denoting the minimum value of matrix after performing the operation.

Example Input:
Input 1:
 A = [
       [2, -1, 5]
       [-2, 3, -2]
     ]
 B = 4
 C = 2
Input 2:
 A = [
       [2, 2]
       [2, 1]
       [1, 2]
     ]
 B = 1
 C = 1
 
Example Output:
Output 1:
 0
Output 2:
 1

Example Explanation:
Explanation 1:
 Select submatrix [-2, 3] and increase elements by 2 twice. Matrix will be after doing two operation:
 [
   [2, -1, 5]
   [2, 7, -2]
 ]
 Select submatrix [7, -2] and increase elements by 2. Matrix will be:
 [
   [2, -1, 5]
   [2, 9, 0]
 ]
 Select submatrix [2, -1] and increase elements by 2. Matrix will be:
 [
   [4, 1, 5]
   [2, 9, 0]
 ]
 All 4 operations are done, minimum element is 0.
Explanation 2:
 Minimum element will be 1.
*/



bool check(vector<vector<int>> &A, int val, int subsz, int op){
    int n = A.size(), m = A[0].size();
    for(int i = 0; i < n; i++){
        int less[m];
        memset(less, 0, sizeof(less));
        for(int j = 0; j < m; j++){
            if(A[i][j] < val){
                less[j] = (val - A[i][j] + 1)/2;
            }
        }
        int dif = 0;
        int temp[m];
        memset(temp, 0, sizeof(temp));
        for(int i = 0; i < m; i++){
            dif += temp[i];
            less[i] += dif;
            if(less[i] > 0){
                op -= less[i];
                if(i + subsz < m){
                    temp[i + subsz] = less[i];
                }
                dif -= less[i];
                if(op < 0){
                    return false;
                }
            }
        }
    }
    return true;
}

int Solution::solve(vector<vector<int> > &A, int B, int C) {
    int n = A.size(), m = A[0].size();
    int lo = 1e9;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            lo = min(lo, A[i][j]);
        }
    }
    int hi = lo + 2 * B;
    int ans = lo;
    while(lo <= hi){
        int mid = (hi+lo)/2;
        if(check(A, mid, C, B)){
            ans = mid;
            lo = mid + 1;
        }
        else{
            hi = mid - 1;
        }
    }
    return ans;
}
