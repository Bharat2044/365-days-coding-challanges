// Question Link: https://www.interviewbit.com/problems/matrix-search/

/*
Matrix Search

Problem Description:
Given a matrix of integers A of size N x M and an integer B. Write an efficient algorithm that searches for integer B in matrix A. 

This matrix A has the following properties:

Integers in each row are sorted from left to right.
The first integer of each row is greater than or equal to the last integer of the previous row.
Return 1 if B is present in A, else return 0.

NOTE: Rows are numbered from top to bottom, and columns are from left to right.

Problem Constraints:
1 <= N, M <= 1000

1 <= A[i][j], B <= 106

Input Format:
The first argument given is the integer matrix A.

The second argument given is the integer B.

Output Format:
Return 1 if B is present in A else, return 0.

Example Input:
Input 1: 
A = [ 
      [1,   3,  5,  7]
      [10, 11, 16, 20]
      [23, 30, 34, 50]

    ]
B = 3
Input 2:
A = [
      [5, 17, 100, 111]
      [119, 120, 127, 131]
    ]
B = 3

Example Output:
Output 1: 
1
Output 2:
0

Example Explanation:
Explanation 1: 
 3 is present in the matrix at A[0][1] position so return 1.
Explanation 2:
 3 is not present in the matrix so return 0.
*/



bool binarysearch(vector<int> &X, int B) {

    int s = 0;

    int e = X.size()-1;

    int m = s + (e-s)/2;

    while (s<=e) {

        if (X[m] == B) return true;

        else if (X[m] > B) e = m-1;

        else s = m +1;

        m = s + (e-s)/2; 

    }

    return false;

}

int Solution::searchMatrix(vector<vector<int> > &A, int B) {
    int x = A[0].size();
    int s = 0;
    int e = A.size()-1;
    int m = s + (e-s)/2;
    
    while ( e >= s ) {
        if (binarysearch(A[m],B) == true) 
            return 1;
        else {
            if (A[m][x-1] < B) 
                s = m+1;
            else 
                e = m-1;
        } 
        m = s + (e-s)/2;
    }

    return 0;
}
