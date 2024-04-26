// Question Link: https://leetcode.com/problems/jump-game-iv/description/

/*
1345. Jump Game IV

Given an array of integers arr, you are initially positioned at the first index of the array.

In one step you can jump from index i to index:
i + 1 where: i + 1 < arr.length.
i - 1 where: i - 1 >= 0.
j where: arr[i] == arr[j] and i != j.
Return the minimum number of steps to reach the last index of the array.
Notice that you can not jump outside of the array at any time.

Example 1:
Input: arr = [100,-23,-23,404,100,23,23,23,3,404]
Output: 3
Explanation: You need three jumps from index 0 --> 4 --> 3 --> 9. Note that index 9 is the last index of the array.
Example 2:
Input: arr = [7]
Output: 0
Explanation: Start index is the last index. You do not need to jump.
Example 3:
Input: arr = [7,6,9,6,9,6,9,7]
Output: 1
Explanation: You can jump directly from index 0 to index 7 which is last index of the array.
 
Constraints:
1 <= arr.length <= 5 * 10^4
-10^8 <= arr[i] <= 10^8
*/



class Solution {
public:
    unordered_map<int, vector<int>> g;
    int n, vis[50005], dis[50005];

    int bfs(int s, vector<int>& arr) {
        vis[s] = 1;
        dis[s] = 0;
        queue<int> q;
        q.push(s);
        while(!q.empty()) {
            int u = q.front();
            q.pop();
            if(u == n-1) return dis[n-1];
            if(u-1 >= 0 and !vis[u-1]) {
                vis[u-1] = 1;
                dis[u-1] = dis[u] + 1;
                q.push(u-1);
            }
            if(u+1 < n and !vis[u+1]) {
                vis[u+1] = 1;
                dis[u+1] = dis[u] + 1;
                q.push(u+1);;
            }
            for(auto v: g[arr[u]]) {
                if(!vis[v]) {
                    vis[v] = 1;
                    dis[v] = dis[u] + 1;
                    q.push(v);
                }
            }
            g[arr[u]].clear();
        }
        return dis[n-1];
    }

    int minJumps(vector<int>& arr) {
        n = arr.size();
        for(int i=0; i<n; i++) {
            g[arr[i]].push_back(i);
        }
        int ans = bfs(0, arr);
        return ans;
    }
};
