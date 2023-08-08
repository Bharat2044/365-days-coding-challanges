// Question Link: https://leetcode.com/problems/spiral-matrix-ii/

/*
59. Spiral Matrix II

Given a positive integer n, generate an n x n matrix filled with elements from 1 to n2 in spiral order.

Example 1:
Input: n = 3
Output: [[1,2,3],[8,9,4],[7,6,5]]
Example 2:
Input: n = 1
Output: [[1]]
 
Constraints:
1 <= n <= 20
*/



class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> ans(n, vector<int>(n));
        int srow = 0, erow = n-1, scol = 0, ecol = n-1, element = 1, total = n*n;
        while(element <= total)    {
            // step-1 : starting row
            for(int i=scol; i<=ecol && element<=total; i++)   {
                ans[srow][i] = element++;
            }
            srow++;

            // step-2 : ending column
            for(int i=srow; i<=erow && element<=total; i++)   {
                ans[i][ecol] = element++;
            }
            ecol--;

            // step-3 : ending row
            for(int i=ecol; i>=scol && element<=total; i--)   {
                ans[erow][i] = element++;
            }
            erow--;

            // step-4 : starting column
            for(int i=erow; i>=srow && element<=total; i--)   {
                ans[i][scol] = element++;
            }
            scol++;
        }

        return ans;
    }
};
