// Qiustion Link: https://www.interviewbit.com/problems/simple-queries/

/*
Simple Queries

Problem Description:
You are given an array A having N integers.
You have to perform the following steps in a given order.
1) generate all subarrays of A.
2) take the maximum element from each subarray of A and insert it into a new array G.
3) replace every element of G with the product of their divisors mod 1e9 + 7.
4) sort G in descending order

You now need to perform Q queries
In each query, you are given an integer K, where you have to find the Kth element in G.

NOTE : Your solution will run on multiple test cases so do clear global variables after using them.

Problem Constraints:
1 <= N <= 1e5
1 <= A[i] <= 1e5
1 <= Q <= 1e5
1 <= k <= (N * (N + 1))/2 

Input Format:
The first argument given is an Array A, having N integers.
The second argument given is an Array B, where B[i] is the ith query.

Output Format:
Return an Array X, where X[i] will have the answer for the ith query.

Example Input:
Input 1:
A = [1, 2, 4]
B = [1, 2, 3, 4, 5, 6]
Input 2:
A = [1, 3]
B = [1]

Example Output:
Output 1:
[8, 8, 8, 2, 2, 1]
Output 2:
[3]

Example Explanation:
Explanation 1:
subarrays of A maximum element
[1] 1
[1, 2] 2
[1, 2, 4] 4
[2] 2
[2, 4] 4
[4] 4
original
G = [1, 2, 4, 2, 4, 4]
after changing every element of G with product of their divisors
G = [1, 2, 8, 2, 8, 8]
after sorting G in descending order
G = [8, 8, 8, 2, 2, 1]

Explanation 2:
Just perform given query.
*/



vector<int> Solution::solve(vector<int> &A, vector<int> &B) {
    int mod = 1e9+7, m = A.size(), n = B.size(), x = *max_element(A.begin(), A.end());
    vector<long long> dp(x+1, 1);

    for(int i = 1; i<= x; i++){
        for(int j = i; j<=x; j += i){
           dp[j] = (dp[j]*i)%mod;
        }
    }

    vector<pair<long long, int>> v;
    stack<int> stk;

    for(int i = 0; i<=m; i++){
        while(!stk.empty() && (i==m || A[stk.top()] <= A[i])){
            long mid = stk.top(); stk.pop();
            int lb = stk.empty() ? -1 : stk.top();
            int rb = i;

            v.push_back({dp[A[mid]], (mid-lb) * (rb - mid)});
        }

        stk.push(i);
    }

    sort(v.begin(), v.end());
    vector<long long> pre(m);
    pre[0] = v[0].second;
    
    for(int i = 1; i<m; i++){
        pre[i] = pre[i-1] + v[i].second;
    }

    vector<int> ans(n);
    
    for(int q = 0; q<n; q++){
        long long k = m*(m+1LL)/2-B[q]+1;
        int x = lower_bound(pre.begin(), pre.end(), k) - pre.begin();
        ans[q] = v[x].first;
    }

    return ans;
}


