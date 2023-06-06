// Question Link: https://leetcode.com/problems/course-schedule/

/*
207. Course Schedule

There are a total of numCourses courses you have to take, labeled from 0 to numCourses - 1. You are given an array prerequisites where prerequisites[i] = [ai, bi] indicates that you must take course bi first if you want to take course ai.

For example, the pair [0, 1], indicates that to take course 0 you have to first take course 1.
Return true if you can finish all courses. Otherwise, return false.

Example 1:
Input: numCourses = 2, prerequisites = [[1,0]]
Output: true
Explanation: There are a total of 2 courses to take. 
To take course 1 you should have finished course 0. So it is possible.
Example 2:
Input: numCourses = 2, prerequisites = [[1,0],[0,1]]
Output: false
Explanation: There are a total of 2 courses to take. 
To take course 1 you should have finished course 0, and to take course 0 you should also have finished course 1. So it is impossible.
 

Constraints:
1 <= numCourses <= 2000
0 <= prerequisites.length <= 5000
prerequisites[i].length == 2
0 <= ai, bi < numCourses
All the pairs prerequisites[i] are unique.
*/


class Solution {
public:
    bool detectCycle(int src ,vector<int>&vis,vector<int>&crvisit,vector<int> adj[]){
        vis[src]=1;
        crvisit[src]=1;
        for(auto it  : adj[src]){
            if(!vis[it]){
                if(detectCycle(it , vis , crvisit , adj)) return true ;
            }
            else if(vis[it]  && crvisit[it]){
                return true ;
            }
        }
        crvisit[src]=0;
        return false ;
    }
    
    bool canFinish(int numCourses, vector<vector<int>>& pq) {
        int n = numCourses;   
        vector<int> adj[n];
        for(auto x : pq){
            vector<int> data = x;
            int a =data[0];
            int b = data[1];
            adj[a].push_back(b);
            
        }
        vector<int> vis(n,0);
        vector<int> crvisit(n,0);
        for(int i=0;i<n;i++){
            if(!vis[i]){
                if(detectCycle(i,vis,crvisit ,adj))
                return false ;
            }
        }
        return true ;
    }
};
