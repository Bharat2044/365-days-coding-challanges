// Question Link: https://leetcode.com/problems/triangle/

/*
120. Triangle

Given a triangle array, return the minimum path sum from top to bottom.

For each step, you may move to an adjacent number of the row below. More formally, if you are on index i on the current row, you may move to either index i or index i + 1 on the next row.

Example 1:
Input: triangle = [[2],[3,4],[6,5,7],[4,1,8,3]]
Output: 11
Explanation: The triangle looks like:
   2
  3 4
 6 5 7
4 1 8 3
The minimum path sum from top to bottom is 2 + 3 + 5 + 1 = 11 (underlined above).
Example 2:
Input: triangle = [[-10]]
Output: -10
 
Constraints:
1 <= triangle.length <= 200
triangle[0].length == 1
triangle[i].length == triangle[i - 1].length + 1
-104 <= triangle[i][j] <= 104
*/



class Solution {
public:
    
    int minimumTotal(vector<vector<int>>& a) {
        
        int n = a.size();
        vector<vector<int>> dp(n,vector<int>(n));
        for(int i=0;i<n;i++){
            dp[n-1][i] = a[n-1][i];
        }

        for(int i=n-2;i>=0;i--){
            for(int j=0;j<=i;j++){
                int down = a[i][j] + dp[i+1][j];
                int dia = a[i][j] + dp[i+1][j+1];

                dp[i][j] = min(down,dia);
            }
        }

        return dp[0][0];
    }
};
