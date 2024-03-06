// Question Link: https://interviewbit.com/problems/stringoholics/

/*
Stringoholics

Problem Description:

You are given an array A consisting of strings made up of the letters 'a' and 'b' only.
Each string goes through a number of operations, where:
1.  At time 1, you circularly rotate each string by 1 letter.
2.  At time 2, you circularly rotate the new rotated strings by 2 letters.
3.  At time 3, you circularly rotate the new rotated strings by 3 letters.
4.  At time i, you circularly rotate the new rotated strings by i % length(string) letters.

Eg: String is "abaa"
At time 1, string is "baaa", as 1 letter is circularly rotated to the back
At time 2, string is "aaba", as 2 letters of the string "baaa" is circularly rotated to the back
At time 3, string is "aaab", as 3 letters of the string "aaba" is circularly rotated to the back
At time 4, string is again "aaab", as 4 letters of the string "aaab" is circularly rotated to the back

At time 5, string is "aaba", as 1 letters of the string "aaab" is circularly rotated to the back
After some units of time, a string becomes equal to its original self.
Once a string becomes equal to itself, it's letters start to rotate from the first letter again (process resets). So, if a string takes t time to get back to the original, at time t+1 one letter will be rotated and the string will be its original self at 2t time.
You have to find the minimum time, where maximum number of strings are equal to their original self.
As this time can be very large, give the answer modulo 109+7.

Note: Your solution will run on multiple test cases so do clear global variables after using them.

Problem Constraints:
1 <= |A| <= 100

Input Format:
A: Array of strings.

Output Format:
Minimum time, where maximum number of strings are equal to their original self.

Example Input:
Input 1:
A: [a, ababa, aba]
Input 2:
A : [a, aa]

Example Output:
Output 1:
4
Output 2:
1
  
Example Explanation:
Explanation 1:
String 'a' is it's original self at time 1, 2, 3 and 4.
String 'ababa' is it's original self only at time 4. (ababa => babaa => baaba => babaa => ababa)
String 'aba' is it's original self at time 2 and 4. (aba => baa => aba)
Hence, 3 strings are their original self at time 4.
Explanation 2:
Both strings are their original self at time 1.
*/


#define pb push_back
#define mp make_pair
#define fi first.first
#define se first.second
#define MOD 1000000007
#define ms(s, n) memset(s, n, sizeof(s))
#define prec(n) fixed<<setprecision(n)
#define eps 0.000001
#define all(v) v.begin(), v.end()
#define bolt ios::sync_with_stdio(0)
#define forr(i,p,n) for(ll i=p;i<n;i++)
typedef long long ll;

ll mult(ll a,ll b, ll p=MOD){return ((a%p)*(b%p))%p;}
ll add(ll a, ll b, ll p=MOD){return (a%p + b%p)%p;}
ll fpow(ll n, ll k, ll p = MOD) {ll r = 1; for (; k; k >>= 1) {if (k & 1) r = r * n%p; n = n * n%p;} return r;}
ll inv(ll a, ll p = MOD) {return fpow(a, p - 2, p);}

ll com(string s){
	ll lps[100003]={0};
    lps[0]=0;
    ll len=0;
    ll p=1;
    while(p<s.length()){
        if(s[p]==s[len]){
            len++;
            lps[p]=len;
            p++;
        }else{
            if(len!=0){
                len=lps[len-1];
            }else{
                lps[p]=0;
                p++;
            }
        }
    }
    len=lps[s.length()-1];
    if(s.length()%(s.length()-len)==0){
		return s.length()-len;
    }else return s.length();
}

ll spf[300003];

void spff(){
	spf[1] = 1;
    for (ll i=2;i<300003;i++)
    	spf[i] = i;

    for (ll i=4; i<300003; i+=2)
        spf[i] = 2;

    for (ll i=3; i*i<300003; i++)
    {
        if (spf[i] == i)
        {
            for (ll j=i*i; j<300003; j+=i)
                if (spf[j]==j)
                    spf[j] = i;
        }
    }
}

int Solution::solve(vector<string> &s) {
    spff();
    ll n=s.size();
    assert(n >= 1 && n <= 100); 
	ll maxx=0;
    ll res[200003]={0};
	for(ll i=0;i<n;i++){
		ll len=com(s[i]);
        for(ll i=1;;i++){
            if(((i*(i+1))/2)%len==0){
				ll temp=i;
				while(temp!=1){
					ll r=spf[temp];
					ll cnt=0;
					while(temp%r==0){
						cnt++;
						temp/=r;
					}
					res[r]=max(res[r],cnt);
				}
				break;
            }
        }
	}
	ll ans=1;
	for(ll i=1;i<=200000;i++){
		ans=mult(ans,fpow(i,res[i]));
	}
	return ans;
}
