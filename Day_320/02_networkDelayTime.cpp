// Question Link: https://leetcode.com/problems/network-delay-time/

/*
743. Network Delay Time

You are given a network of n nodes, labeled from 1 to n. You are also given times, a list of travel times as directed edges times[i] = (ui, vi, wi), where ui is the source node, vi is the target node, and wi is the time it takes for a signal to travel from source to target.

We will send a signal from a given node k. Return the minimum time it takes for all the n nodes to receive the signal. If it is impossible for all the n nodes to receive the signal, return -1.

Example 1:
Input: times = [[2,1,1],[2,3,1],[3,4,1]], n = 4, k = 2
Output: 2
Example 2:
Input: times = [[1,2,1]], n = 2, k = 1
Output: 1
Example 3:
Input: times = [[1,2,1]], n = 2, k = 2
Output: -1
 
Constraints:
1 <= k <= n <= 100
1 <= times.length <= 6000
times[i].length == 3
1 <= ui, vi <= n
ui != vi
0 <= wi <= 100
All the pairs (ui, vi) are unique. (i.e., no multiple edges.)
*/


class Solution {
public:
    vector<pair<int, int>> G[6001];
    
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        int visited[6001] = {0};
        priority_queue<pair<int,int> > PQ;
        for(int i=0;i<=n;i++) {
            visited[i] = 1e7;
        }
        for(int i=0;i<times.size();i++) {
            G[times[i][0]].push_back({times[i][2], times[i][1]});
        }
        int cnt = 1;
        PQ.push({0 ,k});
        int ans = 0;
        visited[k] = 0;
        while(!PQ.empty()) {
            pair<int, int> u = PQ.top();
            PQ.pop();
            for(int i=0;i<G[u.second].size();i++) {
                pair<int, int> v = G[u.second][i];
                int val = (-1 * u.first) + v.first;
                if(visited[v.second]>val) {
                    visited[v.second] = val;
                    PQ.push({-1 * val, v.second});
                }
            }
        }
        for(int i=1;i<=n;i++) {
            if(k==i) continue;
            if(visited[i] == 1e7) continue;
            ans = max(ans, visited[i]);
            cnt++;
        }
        if(cnt == n) {
            return ans;
        }
        return -1;
    }
};
