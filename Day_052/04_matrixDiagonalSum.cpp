// Question Link: https://leetcode.com/problems/matrix-diagonal-sum/

/*
1572. Matrix Diagonal Sum

Given a square matrix mat, return the sum of the matrix diagonals.

Only include the sum of all the elements on the primary diagonal and all the elements on the secondary diagonal that are not part of the primary diagonal.

Example 1:
Input: mat = [[1,2,3],
              [4,5,6],
              [7,8,9]]
Output: 25
Explanation: Diagonals sum: 1 + 5 + 9 + 3 + 7 = 25
Notice that element mat[1][1] = 5 is counted only once.
Example 2:
Input: mat = [[1,1,1,1],
              [1,1,1,1],
              [1,1,1,1],
              [1,1,1,1]]
Output: 8
Example 3:
Input: mat = [[5]]
Output: 5
 
Constraints:
n == mat.length == mat[i].length
1 <= n <= 100
1 <= mat[i][j] <= 100
*/


// Time Complexity = O(n), SC = O(1)
class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        int sum = 0;
        int n = mat.size();

        for (int i=0; i<n; i++) {
            sum += mat[i][i]; 
            sum += mat[n-1-i][i];
        }

        return n % 2 == 0 ? sum : sum - mat[n/2][n/2];
    }
};




// Time Complexity = O(n^2), SC = O(1)
/*
class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        int sum = 0;

        for(int i=0; i<mat.size(); i++) {
            for(int j=0; j<mat[i].size(); j++) {
                if(i==j || i+j==mat[i].size()-1)
                    sum += mat[i][j];
            }
        }

        return sum;
    }
};
*/
