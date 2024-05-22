// Question Link: https://leetcode.com/problems/right-triangles/description/

/*
3128. Right Triangles

You are given a 2D boolean matrix grid.
Return an integer that is the number of right triangles that can be made with the 3 elements of grid such that all of them have a value of 1.

Note:
A collection of 3 elements of grid is a right triangle if one of its elements is in the same row with another element and in the same column with the third element. The 3 elements do not have to be next to each other.

Example 1:
0	1	0
0	1	1
0	1	0
0	1	0
0	1	1
0	1	0
Input: grid = [[0,1,0],[0,1,1],[0,1,0]]
Output: 2
Explanation:
There are two right triangles.

Example 2:
1	0	0	0
0	1	0	1
1	0	0	0
Input: grid = [[1,0,0,0],[0,1,0,1],[1,0,0,0]]
Output: 0
Explanation:
There are no right triangles.

Example 3:
1	0	1
1	0	0
1	0	0
1	0	1
1	0	0
1	0	0
Input: grid = [[1,0,1],[1,0,0],[1,0,0]]
Output: 2
Explanation:
There are two right triangles.

Constraints:
1 <= grid.length <= 1000
1 <= grid[i].length <= 1000
0 <= grid[i][j] <= 1
*/


class Solution {
public:
    
    #define ll long long
    
    long long numberOfRightTriangles(vector<vector<int>>& grid) {
        int n=grid.size(), m=grid[0].size();
        
        vector<vector<int>> top_pre(n,vector<int>(m,0));
        for(int j=0;j<m;j++){
            for(int i=0;i<n;i++) top_pre[i][j] += (i>0 ? top_pre[i-1][j]:0) + grid[i][j];
        }
        
        vector<vector<int>> bottom_pre(n,vector<int>(m,0));
        for(int j=0;j<m;j++){
            for(int i=n-1;i>=0;i--) bottom_pre[i][j] += (i<n-1 ? bottom_pre[i+1][j]:0) + grid[i][j];
        }
        
        vector<vector<int>> left_pre(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++) left_pre[i][j] += (j>0 ? left_pre[i][j-1]:0) + grid[i][j];
        }
        
        vector<vector<int>> right_pre(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            for(int j=m-1;j>=0;j--) right_pre[i][j] += (j<m-1 ? right_pre[i][j+1]:0) + grid[i][j];
        }
        
        ll int ans = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j] == 0) continue;
                
                int c1 = max(0, (bottom_pre[i][j]-1)*(left_pre[i][j]-1));
                    
                int c2 = max(0, (bottom_pre[i][j]-1)*(right_pre[i][j]-1));

                int c3 = max(0, (top_pre[i][j]-1)*(left_pre[i][j]-1));

                int c4 = max(0, (top_pre[i][j]-1)*(right_pre[i][j]-1));

                ans += (c1+c2+c3+c4);
            }
        }
        
        return ans;
    }
};
