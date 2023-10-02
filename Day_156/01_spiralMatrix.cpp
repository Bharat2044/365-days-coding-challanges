// Question Link: https://www.interviewbit.com/problems/spiral-matrix/

/*
Spiral Matrix

Problem Description:
Given an array of A of length B×C.
Make a Spiral matrix (2D array) of B rows and C columns.

Note: See example input for pattern.

Problem Constraints:
1 <= Ai <=105
1 <= B×C <= 105

Input Format:
First argument is an integer array A.
Second argument is an integer B.
Third argument is an integer C.

Output Format:
Return 2D integer array.

Example Input:
Input 1:
A = [1, 2, 4, 8]
B = 2
C = 2
Input 2:
A = [1, 2, 3, 4, 5, 6, 7, 8, 9]
B = 3
C = 3

Example Output:
Output 1:
[[1, 2],
 [8, 4]]
Output 2:
[[1, 2, 3],
 [8, 9, 4],
 [7, 6, 5]]
*/



vector<vector<int> > Solution::solve(vector<int> &A, int B, int C) {
    int left = 0, right = C -1, top = 0, bottom = B -1;
    vector<vector<int>> v(B, vector<int>(C));
    int ind = 0;
   
    while(left<=right and top<=bottom) {
       
        for(int i = left; i <= right; i++){
            v[top][i] =  A[ind++];
        }
        top++;
   
        for(int i = top; i<=bottom; i++){
            v[i][right] = A[ind++];
        }
        right--;
   
        if(top<=bottom){
            for(int i = right; i >= left; i--){
                v[bottom][i] =  A[ind++];
            }
            bottom--;
        }
       
        if(left<=right){
            for(int i = bottom; i >= top; i--){
                v[i][left] =  A[ind++];
            }
            left++;
        }       
    }
    
    return v;
}
