// Question Link: https://leetcode.com/problems/erect-the-fence/

/*
587. Erect the Fence

You are given an array trees where trees[i] = [xi, yi] represents the location of a tree in the garden.
Fence the entire garden using the minimum length of rope, as it is expensive. The garden is well-fenced only if all the trees are enclosed.
Return the coordinates of trees that are exactly located on the fence perimeter. You may return the answer in any order.

Example 1:
Input: trees = [[1,1],[2,2],[2,0],[2,4],[3,3],[4,2]]
Output: [[1,1],[2,0],[4,2],[3,3],[2,4]]
Explanation: All the trees will be on the perimeter of the fence except the tree at [2, 2], which will be inside the fence.
Example 2:
Input: trees = [[1,2],[2,2],[4,2]]
Output: [[4,2],[2,2],[1,2]]
Explanation: The fence forms a line that passes through all the trees.
 
Constraints:
1 <= trees.length <= 3000
trees[i].length == 2
0 <= xi, yi <= 100
All the given positions are unique.
*/



class Solution {
public:
     
    // Geometry and Maths Problem
    // Convex Hull Algorithm is Used

    // Cross Product we are doing
    int Cross_Product_fun(vector<int> p,vector<int> q,vector<int> r){
        int ans = ((q[0]-p[0])*(r[1]-p[1]))-((q[1]-p[1])*(r[0]-p[0]));

        return ans;

    }
    vector<vector<int>> outerTrees(vector<vector<int>>& trees) {
        int sz = trees.size();

        if(sz<=3){
            return trees;
        }
        else{

            sort(trees.begin(),trees.end());

            vector<vector<int>> up_hull;
            vector<vector<int>> low_hull;

            // for Upper Hull

            up_hull.push_back(trees[0]);
            up_hull.push_back(trees[1]);

            for(int j=2;j<sz;j++){
                int n = up_hull.size();

                while(n>=2 && Cross_Product_fun(up_hull[n-2],up_hull[n-1],trees[j]) > 0){
                    up_hull.pop_back();
                    n--;
                }

                up_hull.push_back(trees[j]);
            }

            // for Lower Hull

            low_hull.push_back(trees[sz-1]);
            low_hull.push_back(trees[sz-2]);

            for(int j=sz-3;j>=0;j--){
                int m = low_hull.size();

                while(m>=2 && Cross_Product_fun(low_hull[m-2],low_hull[m-1],trees[j]) > 0){
                    low_hull.pop_back();
                    m--;
                }

                low_hull.push_back(trees[j]);
            }

            // Finally Connecting our Upper Hull and Lower Hull

            up_hull.insert(up_hull.end(),low_hull.begin(),low_hull.end());

            sort(up_hull.begin(),up_hull.end());

            up_hull.erase(unique(up_hull.begin(),up_hull.end()),up_hull.end());

            return up_hull;

        }

    }
};
