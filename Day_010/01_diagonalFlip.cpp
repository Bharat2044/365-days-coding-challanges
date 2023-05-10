// Question Link: https://www.interviewbit.com/problems/diagonal-flip/

/*
Diagonal Flip:

Problem Description:
Given a square binary matrix of drimensions N×N.
Flip the matrix diagonally and return the matrix.

Problem Constraints:
1 <= N <= 1000
A[i][j] ={0, 1}

Input Format:
Given a 2D integer array.

Output Format:
Return a 2D integer array.

Example Input:
Input 1:
A = 4
B = [[1, 0],
     [0, 1]]
Input 2:
A = [[1, 0],
     [1, 0]]

Example Output:
Output 1:
[[1, 0],
 [0, 1]]
Output 2:
[[1, 1],
 [0, 0]]


Example Explanation:
Explanation 1:
We will swap the values at positions (1, 2) and (2, 1).
Explanation 2:
We will swap the values at positions (1, 2) and (2, 1).
*/


// Time Complexity = O(n^2), Space Complexity = O(1)
vector<vector<int> > Solution::solve(vector<vector<int> > &A) {
    
    for(int i=0; i<A.size();i++){
        
        for(int j=i+1; j<A.size();j++)
            swap(A[i][j], A[j][i]);
    }
    
    return A;
}
