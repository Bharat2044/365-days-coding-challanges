// Question Link: https://www.interviewbit.com/problems/scaler-subarrays-ii/

/*
Scaler Subarrays II

Problem Description:
You are given an array A of size N.
A subarray A [ l ... r ] contains all the elements A[l], A[l+1], .... , A[r]. A subarray A [ l ... r ] is called a scaler subarray if max( A [ l ... r ] ) and A[l] + A[r] are congruent modulo B.
Here, max( A [ l ... r ] ) is the maximum value of this subarray.
Given an integer n > 1, called a modulus, two integers a and b are said to be congruent modulo n, if n is a divisor of their difference (i.e. if there is an integer k such that
a − b = k n).
Find the total number of scaler subarrays of A. Since the answer can be large, return it modulo 109 + 7.

Problem Constraints:
1 <= N, B <= 5 x 10^5
1 <= A[i] <= 10^9

Input Format:
The first argument contains an integer array A of size N.
The second argument contains an integer B.

Output Format:
Return the number of scaler subarrays of A modulo 109 + 7.

Example Input:
Input 1:
  A : [ 8, 7 ]
  B : 4
Input 2:
  A : [ 4, 5, 3, 8, 8 ]
  B : 5

Example Output:
Output 1:
  1
Output 2:
  3

Example Explanation:
Explanation 1:
  The subarray [8] is scaler because max([8]) = 8 and A[l] + A[r] = 16. 
  8 and 16 are congruent modulo 4 because 16 - 8 = 8 is divisible by 4.
Explanation 2:
  Scaler subarrays are [5], [5, 3, 8] and [5, 3, 8, 8].
*/



int n,a[500005],ab[500005],b,f[500005];
int scaler(int l,int r){
    if(l == r)
        return (ab[l] == 0);
    int mid = (l+r)>>1;
    int ans = scaler(l,mid) + scaler(mid+1,r);
    int mx = -1, idx, R = mid;
    for(int i = mid; i >= l; i--){
        if(a[i] > mx){
            mx = a[i];
            idx = i;
        }
        while(R+1 <= r and a[R+1] <= mx){
            R++;
            f[ab[R]]++;
        }
        int rem = ab[idx] - ab[i];
        if(rem < 0) rem += b;
        ans += f[rem];
    }
    for(int i = mid+1; i <= r; i++)
        f[ab[i]] = 0;
    mx = -1;
    int L = mid+1;
    for(int i = mid+1; i <= r; i++){
        if(a[i] > mx){
            mx = a[i];
            idx = i;
        }
        while(L-1 >= l and a[L-1] < mx){
            L--;
            f[ab[L]]++;
        }
        int rem = ab[idx] - ab[i];
        if(rem < 0) rem += b;
        ans += f[rem];
    }
    for(int i = l; i <= mid; i++)
        f[ab[i]] = 0;
    return ans;
}
int Solution::solve(vector<int> &A, int B) {
    n = A.size();
    assert(n>=1 && n<=500000);
    assert(B>=1 && B<=500000);
    for(int a:A)assert(a>=1 && a<=1000000000);
    for(int i = 0; i < n; i++)
        a[i] = A[i];
    b = B;
    for(int i = 0; i < n; i++)
        ab[i] = (a[i]%b);
    return scaler(0,n-1);
}
