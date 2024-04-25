// Question Link: https://www.interviewbit.com/problems/largest-distance-between-nodes-of-a-tree/

/*
Largest Distance between nodes of a Tree

Problem Description:
Given an arbitrary unweighted rooted tree which consists of N nodes.
The goal of the problem is to find largest distance between two nodes in a tree.
Distance between two nodes is a number of edges on a path between the nodes (there will be a unique path between any pair of nodes since it is a tree).
The nodes will be numbered 0 through N - 1.
The tree is given as an array A, there is an edge between nodes A[i] and i (0 <= i < N). Exactly one of the i's will have A[i] equal to -1, it will be root node.

Problem Constraints:
1 <= N <= 40000

Input Format:
First and only argument is an integer array A of size N.

Output Format:
Return a single integer denoting the largest distance between two nodes in a tree.

Example Input:
Input 1:
 A = [-1, 0, 0, 0, 3]

Example Output:
Output 1:
 3

Example Explanation:
Explanation 1:
 node 0 is the root and the whole tree looks like this: 
          0
       /  |  \
      1   2   3
               \
                4
 One of the longest path is 1 -> 0 -> 3 -> 4 and its length is 3, thus the answer is 3.
*/




void dfs(int node,vector<int>adj[],vector<int>&vis,int &max, int temp,int &req) {
    vis[node]=1;
    temp++;
    
    if(max<temp) {
        max=temp;
        req=node;
    }
    
    for(auto it: adj[node]) {
        if(!vis[it])
            dfs(it,adj,vis,max,temp,req);
    }
    
    return;
}

int Solution::solve(vector<int> &A) {
    int n=A.size();
    int root;
    vector<int>adj[n];
    
    for(int i=0;i<n;i++) {
        if(A[i]!=-1) {
            adj[i].push_back(A[i]);
            adj[A[i]].push_back(i);
        }
        else 
            root=i;
    }
    
    int max=0,temp=0,req=-1;
    vector<int>vis(n,0);
    
    dfs(root,adj,vis,max,temp,req);
    
    max=0;
    vector<int>vis2(n,0);
    
    dfs(req,adj,vis2,max,temp,req);
    
    return max-1;
}
