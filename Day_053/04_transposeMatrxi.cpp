// Question Link: https://leetcode.com/problems/transpose-matrix/description/

/*
867. Transpose Matrix

Given a 2D integer array matrix, return the transpose of matrix.

The transpose of a matrix is the matrix flipped over its main diagonal, switching the matrix's row and column indices.
 
Example 1:
Input: matrix = [[1,2,3],[4,5,6],[7,8,9]]
Output: [[1,4,7],[2,5,8],[3,6,9]]
Example 2:
Input: matrix = [[1,2,3],[4,5,6]]
Output: [[1,4],[2,5],[3,6]]
 
Constraints:
m == matrix.length
n == matrix[i].length
1 <= m, n <= 1000
1 <= m * n <= 105
-109 <= matrix[i][j] <= 109
*/



// Time Complexity = O(n*m), Space Complexity = O(n*m)
class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        
        vector<vector<int>> res(m, vector<int> (n)); // matrix creation

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++)
                res[j][i] = matrix[i][j]; // filling the matrix in transpose form
        }
        
        return res;
    }
};
