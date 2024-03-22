// Question Link: https://www.interviewbit.com/problems/consecutive-losses/

/*
Consecutive Losses

Problem Description:
India and Pakistan are playing a bilateral series of A matches. Now, you know that India won exactly 
B matches. We know that there are ACB ways in which India could 
win B out of the A matches played. Here NCR is 
the number of ways to choose R objects out of N objects. 

Having known that we want to know the number of possible results in which the maximum consecutive number of matches lost 
by India is exactly K. 

We need to find that count for all K from 1 to A-B. 
Since the answer can be large, calculate it modulo 10^9 + 7.

Problem Constraints
1 <= B < A <= 5 x 10^5

Input Format:
The two arguments are integers A and B, denoting the total number of matches played and matches won by India respectively.

Output Format:
Return an array of length A - B, the ith element denotes the number of possible results 
in which maximum consecutive losses is exactly equal to i. 
Since the answer can be large, calculate it modulo 10^9 + 7.

Example Input:
Input 1:
  A : 5
  B : 2
Input 2:
  A : 4
  B : 1

Example Output:
Output 1:
  [1, 6, 3]
Output 2:
  [0, 2, 2]

Example Explanation:
  Explanation 1:
  Let's denote a win by W and a defeat by L.
  So, possible number of ways in which India could win 2 out of 5 matches are-
  1.  WWLLL - Maximum 3 consecutive losses
  2.  WLWLL - Maximum 2 consecutive losses
  3.  WLLWL - Maximum 2 consecutive losses
  4.  WLLLW - Maximum 3 consecutive losses
  5.  LWWLL - Maximum 2 consecutive losses
  6.  LWLWL - Maximum 1 consecutive loss
  7.  LWLLW - Maximum 2 consecutive losses
  8.  LLWWL - Maximum 2 consecutive losses
  9.  LLWLW - Maximum 2 consecutive losses
  10. LLLWW - Maximum 3 consecutive losses
Explanation 2:
  Possible outcomes are- 
  1. WLLL - Maximum 3 consecutive losses
  2. LWLL - Maximum 2 consecutive losses
  3. LLWL - Maximum 2 consecutive losses
  4. LLLW - Maximum 3 consecutive losses
*/



const int M=1e9+7;
int expo(int a,int b,int mod){
    int ans=1;
    while(b){
        if(b&1)
            ans=(ans*1LL*a)%mod;
        a=(a*1LL*a)%mod;
        b>>=1;
    }
    return ans;
}
const int N=500005;
int f[N],inv[N];
void preprocess()
{
    f[0]=1;
    for(int i=1;i<N;i++)
        f[i]=(i*1LL*f[i-1])%M;
    inv[N-1]=expo(f[N-1],M-2,M);
    for(int i=N-2;i>=0;i--)
        inv[i]=((i+1)*1LL*inv[i+1])%M;
}
int C(int n,int r){
	if(r>n)
		return 0;
    return (((f[n]*1LL*inv[r])%M)*1LL*inv[n-r])%M;
}
vector<int> Solution::solve(int A, int B) {
    preprocess();
    int n=A,k=B;
    int p=0;
    vector<int>res;
    for(int m = 1; m <= n-k; m++){
    	int cur=0;
    	for(int r = 0; r <= (n-k)/(m+1); r++){
    		int temp = (C(k+1,r) * 1LL * C(n-(m+1)*r,k))%M;
    		if(r&1){
    			cur-=temp;
    			if(cur<0)
    				cur+=M;
    		}
    		else{
    			cur+=temp;
    			if(cur>=M)
    				cur-=M;

    		}
    	}
    	res.push_back((cur-p+M)%M);
    	p=cur;
    }
    return res;
}
