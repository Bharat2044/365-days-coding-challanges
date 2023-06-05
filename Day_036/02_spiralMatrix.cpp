// Question Link: https://leetcode.com/problems/spiral-matrix/

/*
54. Spiral Matrix:

Given an m x n matrix, return all elements of the matrix in spiral order. 

Example 1:
Input: matrix = [[1,2,3],[4,5,6],[7,8,9]]
Output: [1,2,3,6,9,8,7,4,5]
Example 2:
Input: matrix = [[1,2,3,4],[5,6,7,8],[9,10,11,12]]
Output: [1,2,3,4,8,12,11,10,9,5,6,7] 

Constraints:
m == matrix.length
n == matrix[i].length
1 <= m, n <= 10
-100 <= matrix[i][j] <= 100
*/


class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        
        vector<int> ans;
        int st = 0;
        int sz = m * n;
        
        while (ans.size() < sz) {
            for (int i=st; ans.size()<sz && i<n-st; i++) 
                ans.push_back(mat[st][i]);
            
            for (int i=st+1; ans.size()<sz && i<m-st; i++) 
                ans.push_back(mat[i][n - st - 1]);
            
            for (int i=n-2-st; ans.size()<sz && i>=st; i--) 
                ans.push_back(mat[m - 1 - st][i]);
                
            for (int i=m-2-st; ans.size()<sz && i>=st+1; i--) 
                ans.push_back(mat[i][st]);
            st++;
        }
        
        return ans;
    }
};
