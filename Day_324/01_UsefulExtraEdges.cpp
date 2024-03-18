// Question Link: https://www.interviewbit.com/problems/useful-extra-edges/

/*
Useful Extra Edges

Problem Description:
Given a graph of A nodes. Also given the weighted edges in the form of array B.
You are also given starting point C and destination point D.
Also given are some extra edges in the form of vector E.
You need to find the length of the shortest path from C to D if you can use maximum one road from the given roads in E.
All roads are bidirectional.

Problem Constraints:
1 <= A <= 100000
1 <= |B| <= 100000
1 <= C, D <= A
1 <= |E| <= 300
All lengths of the roads lie between 1 and 1000.

Input Format:
First argument is the integer A.
Second argument is the vector of vectors B.
Third argument is the integer C.
Fourth argument is the integer D.
Fifth argument is the vector of vectors E.

Output Format:
Return -1 if C is not reachable from D. Else return the shortest distance between them.

Example Input:
Input 1:
A = 3
B = [   [1, 2, 1]
        [2, 3, 2]
    ]
C = 1
D = 3
E = [   [1, 3, 2]
    ]
Input 2:
A = 4
B = [   [1, 2, 1]
        [2, 3, 2]
        [3, 1, 4]
    ]
C = 1
D = 4
E = [   [1, 3, 2]
    ]

Example Output:
Output 1:
2
Output 2:
-1
 
Example Explanation:
Explanation 1:
Use the direct edge from 1 to 3. It has shortest path from 1 to 3.
Explanation 2:
4 cannot be reached from 1.
*/



int Solution::solve(int A, vector<vector<int> > &B, int C, int D, vector<vector<int> > &E) {
    vector<pair<int,pair<int,int>>>adj[A+1];
    //{node,{wt,type}}
    for(auto it:B)
    {
        adj[it[0]].push_back({it[1],{it[2],0}});
        adj[it[1]].push_back({it[0],{it[2],0}});
    }
    for(auto it:E)
    {
        adj[it[0]].push_back({it[1],{it[2],1}});
        adj[it[1]].push_back({it[0],{it[2],1}});
    }
    vector<vector<int>>dis(A+1,vector<int>(2,1e9));
    dis[C][0]=0;dis[C][1]=0;
    priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>pq;
    //{wt,node,type}
    pq.push({0,{C,0}});
    pq.push({0,{C,1}});
    while(!pq.empty())
    {
        int wt=pq.top().first;
        int node=pq.top().second.first;
        int type=pq.top().second.second;
        pq.pop();
        for(auto it:adj[node])
        {
            int adj_node=it.first;
            int pathwt=it.second.first;
            int adjtype=it.second.second;
            if(type==1)
            {
                if(adjtype==0)
                {
                    if(wt+pathwt < dis[adj_node][1])
                    {
                        dis[adj_node][1]=wt+pathwt;
                        pq.push({dis[adj_node][1],{adj_node,1}});
                    }
                }
            }
            else if(type==0)
            {
                if(adjtype==0)
                {
                    if(wt+pathwt < dis[adj_node][0])
                    {
                        dis[adj_node][0]=wt+pathwt;
                        pq.push({dis[adj_node][0],{adj_node,0}});
                    }
                }
                if(adjtype==1)
                {
                    if(wt+pathwt < dis[adj_node][1])
                    {
                        dis[adj_node][1]=wt+pathwt;
                        pq.push({dis[adj_node][1],{adj_node,1}});
                    }
                }
            }
        }
    }
    if(dis[D][0]==1e9 && dis[D][1]==1e9) return -1;
    return min(dis[D][0],dis[D][1]);
}
