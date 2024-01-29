// Question Link: https://www.interviewbit.com/problems/subarray-cost-sum/

/*
Subarray Cost Sum

Problem Description:
Let's the sum of the array S be sum(S) and the maximum be max(S). The cost of an array S is ceil(sum(S)/2) * max(S). ceil(x) is the smallest integer not less than x.
You have an array A of length N. Find the sum of the cost of all the subarrays of this array.
Since the answer can be large, return it modulo 109 + 7.

Problem Constraints:
1 <= N <= 5 x 105
1 <= A[i] <= 106

Input Format:
The first and only argument contains an integer array A of length N.

Output Format:
Return the sum of cost of all subarrays modulo 109 + 7.

Example Input:
Input 1:
A : [ 1, 2 ]
Input 2:
A : [5]

Example Output:
Output 1:
7
Output 2:
15

Example Explanation:
Explanation 1:
The array has 3 subarrays-
  1. [1] - Cost = 1 * ceil(1/2) = 1
  2. [2] - Cost = 2 * ceil(2/2) = 2
  3. [1, 2] - Cost = 2 * ceil(3/2) = 4
  Sum of cost = 7
Explanation 2:
It has only one subarray. Cost is 5 * ceil(5/2) = 15
*/



int n,a[500005],s[3][500005],L[500005],R[500005];
const int mod = 1e9 + 7;
int f(int l,int mid,int r){
    int sum1 = ((mid - l + 1)*1ll*(s[1][r]-s[1][mid-1]+mod)%mod)%mod;
    int sum2 = ((r-mid+1)*1ll*(s[1][mid-1]-(l>=2?s[1][l-2]:0)+mod)%mod)%mod;
    int sum = (sum1 - sum2 + mod)%mod;
    int c1 = (s[2][mid-1] - (l >= 2 ? s[2][l-2]:0));
    int c2 = (s[2][r] - s[2][mid-1]);
    int odd = (c1 *1ll* (r-mid+1-c2) + c2 * 1ll * (mid-l+1-c1))%mod;
    sum=(sum+odd)%mod;
    sum=(sum*1ll*((mod+1)/2))%mod;
    return sum;
}
int Solution::solve(vector<int> &A) {
    int n=A.size();
    for(int i=1;i<=n;i++){
        a[i]=A[i-1];
        s[0][i]=(s[0][i-1]+a[i])%mod;
        s[1][i]=(s[0][i]+s[1][i-1])%mod;
        s[2][i]=(s[2][i-1]+(s[0][i]&1));
    }
    for(int i=1;i<=n;i++){
        L[i]=i-1;
        while(L[i] and a[L[i]]<a[i])
            L[i]=L[L[i]];
    }
    for(int i=n;i>=1;i--){
        R[i]=i+1;
        while(R[i]<=n and a[R[i]]<=a[i])
            R[i]=R[R[i]];
    }
    int ans=0;
    for(int i=1;i<=n;i++){
        ans=(ans+a[i]*1ll*f(L[i]+1,i,R[i]-1))%mod;
    }
    return ans;    
}
