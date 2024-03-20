// Question Link: https://www.interviewbit.com/problems/queries-on-a-tree/

/*
Queries On A Tree

Problem Description:
You are given a tree of size N.
The edges are given by the vector P of size N-1 where ith element represents an edge between i+1 and P[i]. (1-based indexing)
You need to answer Q queries on it.
In each query, you are given a set of nodes S.
You need to find the size of the minimal connected subgraph (which will also be a tree) containg all nodes in the set S.

Problem Constraints:
1 ≤ N, Q, summation |S| ≤ 10^5
1 ≤ S[i] ≤ N

Input Format:
Input consists of 2 arguments, first is the array A = P of size N-1 and second is the 2D array B of size (sum |S|) x 2 representing the queries in the same order.
Here, A and B are the names of the arguments in the function provided to you.
The queries are given in the format (qid, node) where qid is the query number and node is one of the nodes in the set S[qid].
It is guaranteed that queries are numbered consecutively starting from 1.
Refer samples for more details.

Output Format:
Return a vector of integers, the answer to all the queries in increasing order of qid.

Example Input:
Input 1:
P = [1, 2, 3, 4]
queries = [
                [1, 3],
                [1, 5]
           ]
Input 2:
A = [1, 1, 1, 1]
queries = [
                [1, 1],
                [1, 2],
                [1, 3],
                [2, 2],
                [2, 4],
                [3, 5]
           ]

Example Output:
Output 1:
[3]
Output 2:
[3, 3, 1]

Example Explanation:
Explanation 1:
There is only one query.
Query 1:
 Set S = {3, 5}
 We must take subgraph formed by {3, 4, 5}. Therefore answer is 3.
Explanation 2:
There are 3 queries.
Query 1:
 Set S = {1, 2, 3}
 If we just take these nodes, the subgraph is already connected and is minimal. Therefore answer is 3.
Query 2:
 Set S = {2, 4}
 We must take subgraph formed by {2, 1, 4}. Therefore answer is 3.
Query 3:
 Set S = {5}
 We just take node 5 here. Therefore answer is 1.
*/



#define ll          long long
#define pb          push_back
#define pii         pair<int,int>
#define vi          vector<int>
#define vii         vector<pii>
#define mi          map<int,int>
#define mii         map<pii,int>
#define all(a)      (a).begin(),(a).end()
#define x           first
#define y           second
#define sz(x)       (int)x.size()
#define endl        '\n'
#define hell        1000000007
#define rep(i,a,b)  for(int i=a;i<b;i++)
using namespace std;
int n,q,p[100005],h[100005],dp[20][100005],queries[100005][2],cnt,tim[100005];
vii v[100005];
vi a[100005];
void dfs(int node){
	tim[node]=++cnt;
	for(auto i:a[node]){
		dfs(i);
	}
}
int lca(int U,int V){
    if(h[U]>h[V]) swap(U,V);
    for(int i=19;i>=0;i--){
        if(h[V]-(1<<i)>=h[U]) V=dp[i][V];
    }
    if(U==V) return U;
    for(int i=19;i>=0;i--){
        if(dp[i][U]!=dp[i][V]) U=dp[i][U],V=dp[i][V];
    }
    return dp[0][U];
}
vector<int> Solution::solve(vector<int> &A, vector<vector<int> > &B) {
    n=sz(A)+1;
    rep(i,1,n+1) a[i].clear();
    cnt=0;
    p[1]=1;
    dp[0][1]=1;
    h[1]=1;
    rep(i,2,n+1){
    	p[i]=A[i-2];
    	dp[0][i]=p[i];
    	h[i]=h[p[i]]+1;
    	a[p[i]].pb(i);
    }
    rep(i,1,20){
    	rep(j,1,n+1){
    		dp[i][j]=dp[i-1][dp[i-1][j]];
    	}
    }
    dfs(1);
    q=sz(B);
    rep(i,1,q+1) v[i].clear();
    rep(i,0,q){
    	queries[i][0]=B[i][0];
    	queries[i][1]=B[i][1];
    	v[queries[i][0]].pb({tim[queries[i][1]],queries[i][1]});
    }
    q=queries[q-1][0];
    vi res;
    rep(i,1,q+1){
    	sort(all(v[i]));
    	int ans=h[v[i][0].y]-h[lca(v[i].back().y,v[i][0].y)]+1;
    	rep(j,1,sz(v[i])) ans+=h[v[i][j].y]-h[lca(v[i][j].y,v[i][j-1].y)];
        res.pb(ans);
    }
    return res;
}


