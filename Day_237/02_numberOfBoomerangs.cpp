// Question Link: https://leetcode.com/problems/number-of-boomerangs/

/*
447. Number of Boomerangs

You are given n points in the plane that are all distinct, where points[i] = [xi, yi]. A boomerang is a tuple of points (i, j, k) such that the distance between i and j equals the distance between i and k (the order of the tuple matters).

Return the number of boomerangs.

Example 1:
Input: points = [[0,0],[1,0],[2,0]]
Output: 2
Explanation: The two boomerangs are [[1,0],[0,0],[2,0]] and [[1,0],[2,0],[0,0]].
Example 2:
Input: points = [[1,1],[2,2],[3,3]]
Output: 2
Example 3:
Input: points = [[1,1]]
Output: 0
 
Constraints:
n == points.length
1 <= n <= 500
points[i].length == 2
-104 <= xi, yi <= 104
All the points are unique.
*/



class Solution {
public:
    int numberOfBoomerangs(vector<vector<int>>& points) {
        int n = points.size ();
        
        vector <vector <int>> dis (n, vector <int> (n, 0));
        for (int i = 1; i < n; i++)
            for (int j = 0; j < i; j++)
            {
                int dist = distinct (points, i, j);
                dis [i][j] = dist;
                dis [j][i] = dist;
            }
        int res = 0;
        for (int i = 0; i < n; i++)
        {
            vector <int>& len = dis[i];
            sort (len.begin (), len.end ());
            int last = len [0], count = 1;
            for (int j = 1; j < len.size (); j++)
            {
                if (len [j] == last)
                    count++;
                else
                {
                    res += count * (count - 1);
                    count = 1;
                    last = len [j];
                }
            }
            res += count * (count - 1);
        }
        return res;
    }
    int distinct (vector<vector<int>>& points, int i, int j)
    {
        vector<int>& a = points[i];
        vector<int>& b = points[j];
        return (a[0]-b[0])*(a[0]-b[0]) + (a[1]-b[1])*(a[1]-b[1]);
    }
};
