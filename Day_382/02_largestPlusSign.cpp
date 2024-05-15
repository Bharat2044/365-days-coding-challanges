// Question Link: https://leetcode.com/problems/largest-plus-sign/description/

/*
764. Largest Plus Sign

You are given an integer n. You have an n x n binary grid grid with all values initially 1's except for some indices given in the array mines. The ith element of the array mines is defined as mines[i] = [xi, yi] where grid[xi][yi] == 0.
Return the order of the largest axis-aligned plus sign of 1's contained in grid. If there is none, return 0.
An axis-aligned plus sign of 1's of order k has some center grid[r][c] == 1 along with four arms of length k - 1 going up, down, left, and right, and made of 1's. Note that there could be 0's or 1's beyond the arms of the plus sign, only the relevant area of the plus sign is checked for 1's.

Example 1:
Input: n = 5, mines = [[4,2]]
Output: 2
Explanation: In the above grid, the largest plus sign can only be of order 2. One of them is shown.
Example 2:
Input: n = 1, mines = [[0,0]]
Output: 0
Explanation: There is no plus sign, so return 0.
 
Constraints:
1 <= n <= 500
1 <= mines.length <= 5000
0 <= xi, yi < n
All the pairs (xi, yi) are unique.
*/



class Solution {
public:
    int orderOfLargestPlusSign(int n, vector<vector<int>>& mines) {
        vector<vector<int>> up(n, vector<int>(n, 0)), down(n, vector<int>(n, 0)), left(n, vector<int>(n, 0)), right(n, vector<int>(n, 0));

        unordered_map<int, unordered_map<int,int>> mp;
        for(auto &p : mines)
            mp[p[0]][p[1]]++;

        for(int j = 0; j < n; j++){
            for(int i = 0; i < n; i++){
                if(mp[i].find(j) != mp[i].end())
                    up[i][j] = 0;
                else if(i == 0)
                    up[i][j] = 1;
                else
                    up[i][j] = 1 + up[i - 1][j];
            }
        }

        for(int j = 0; j < n; j++){
            for(int i = n - 1; i >= 0; i--){
                if(mp[i].find(j) != mp[i].end())
                    down[i][j] = 0;
                else if(i == n - 1)
                    down[i][j] = 1;
                else
                    down[i][j] = 1 + down[i + 1][j];
            }
        }

        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(mp[i].find(j) != mp[i].end())
                    left[i][j] = 0;
                else if(j == 0)
                    left[i][j] = 1;
                else
                    left[i][j] = 1 + left[i][j - 1];
            }
        }

        for(int i = 0; i < n; i++){
            for(int j = n - 1; j >= 0; j--){
                if(mp[i].find(j) != mp[i].end())
                    right[i][j] = 0;
                else if(j == n - 1)
                    right[i][j] = 1;
                else
                    right[i][j] = 1 + right[i][j + 1];
            }
        }

        int res = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                
                res = max(res, min(left[i][j], min(right[i][j], min(up[i][j], down[i][j]))));
                
            }
        }
        return res;
    }
};
