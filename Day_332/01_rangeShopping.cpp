// Question Link: https://www.interviewbit.com/problems/range-shopping/

/*
Range Shopping

Problem Description:
Hamid is visiting a fair near his village. There are N shops of toys arranged in a line from left to right numbered 1 to N. There are two types of toys in each shop. The toy of type 1 costs A[i][0] coins and the toy of type 2 costs A[i][1] coins.
Now, he asks you to solve Q queries for him. Each query will be of type-
l r x y - He visits each shop from l to r in this order and he will buy exactly one toy from each of the visited shops. But, he wants to buy at least x toys of type 1 and at least y toys of type 2. Help him find the minimum cost for buying the toys. Since the answer can be large, return it modulo 109 + 7.

Problem Constraints:
1 <= N, Q <= 10^5
1 <= l <= r <= N
0 <= x + y <= r-l+1
1 <= A[i][0], A[i][1] <= 10^9

Input Format:
The first argument contains a 2D array A of size N x 2, denoting the prices of toys.
The second argument contains a 2D array B of size Q x 4, denoting the queires.

Output Format:
Return an array of size Q denoting the answers to the queries. 

Example Input:
Input 1:
  A : 
  [
    [1, 2]
    [4, 2]
    [3, 2]
    [4, 3]
  ]
  B : 
  [
    [2, 3, 1, 1]
    [1, 4, 2, 1]
  ]
Input 2:
  A : 
  [
    [2, 3]
    [4, 5]
    [2, 1]
  ]
  B : 
  [
    [2, 3, 0, 1]
  ]

Example Output:
Output 1:
  [5, 9]
Output 2:
  [5]

Example Explanation:
Explanation 1:
  1. You can buy toy of type 2 in shop 2 with cost 2 and toy of type 1 in shop 3 with cost 3. 
  2. You can buy toy of type 1 in shop 1 with cost 1, toy of type 2 in shop 2 with cost 3, 
     toy of type 1 in shop 3 with cost 3 and toy of type 2 in shop 4 with cost 3. 
     So, you bought 2 toys of type 1 and 2 toys of type 2.
Explanation 2:
  Buy toy of type 1 in shop 2 and toy of type 2 in shop 3.
*/



const int N = 100005, mod = 1e9 + 7;
vector<int> seg[4*N], sm[4*N];
int n, q, a[N], b[N], sa[N], neg[N];
void build(int node, int l, int r, vector< pair<int, int> > &v)
{
    if (l == r) {
        seg[node].push_back(v[l].second);
        sm[node].push_back((v[l].first+mod) % mod);
        return;
    }
    int mid = (l + r) / 2;
    build(2 * node, l, mid, v);
    build(2 * node + 1, mid + 1, r, v);
    merge(seg[2 * node].begin(), seg[2 * node].end(), seg[2 * node + 1].begin(), seg[2 * node + 1].end(), back_inserter(seg[node]));
    for(int i : seg[node]){
        sm[node].push_back((sm[node].size() ? sm[node].back() : 0) + b[i] - a[i]);
        sm[node].back() = (sm[node].back() % mod + mod) % mod;
    }
}
int query(int node, int l, int r, int x, int y, int k)
{
    if (l == r)
        return sm[node][0]*k;
    int mid = (l + r) / 2;
    int last = (upper_bound(seg[2 * node].begin(), seg[2 * node].end(), y) - seg[2 * node].begin());
    int first = (lower_bound(seg[2 * node].begin(), seg[2 * node].end(), x) - seg[2 * node].begin());
    int M = last - first;
    if (M >= k) 
        return query(2 * node, l, mid, x, y, k);
    else 
        return ((( ( last ? sm[2 * node][last - 1] : 0 ) - ( first ? sm[2 * node][first - 1] : 0 ) ) % mod + query(2 * node + 1, mid + 1, r, x, y, k - M) ) % mod + mod)%mod;
}
vector<int> Solution::solve(vector<vector<int> > &A, vector<vector<int> > &B) {
    n = A.size();
    for(int i = 0; i < 4*n; i++){
        seg[i].clear();
        sm[i].clear();
    }
    vector< pair<int, int> > v;
    for(int i = 0; i < n; i++){
        a[i] = A[i][0], b[i] = A[i][1];
        sa[i] = ((i ? sa[i-1] : 0) + a[i])%mod;
        neg[i] = (i ? neg[i-1] : 0) + int(b[i] < a[i]);
        v.push_back({b[i] - a[i], i});
    }
    sort(v.begin(), v.end());
    build(1, 0, n-1, v);
    q = B.size();
    vector<int>res;
    for(int i = 0; i < q; i++){
        int l = B[i][0], r = B[i][1], x1 = B[i][2], x2 = B[i][3];
        l--, r--;
        int ans = (sa[r] - (l ? sa[l-1] : 0) + mod ) % mod, good = neg[r] - (l ? neg[l-1] : 0);
        ans = (ans + query(1, 0, n-1, l, r, min( max(good, x2), r - l + 1 - x1 )))%mod;
        res.push_back(ans);
    }
    return res;
}
