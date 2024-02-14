// Question Link: https://www.interviewbit.com/problems/city-tour/

/*
City Tour

Problem Description:
There are A cities numbered from 1 to A. You have already visited M cities, the indices of which are given in an array B of M integers.

If a city with index i is visited, you can visit either the city with index i-1 (i >= 2) or the city with index i+1 (i < A) if they are not already visited. Eg: if N = 5 and array M consists of [3, 4], then in the first level of moves, you can either visit 2 or 5.
You keep visiting cities in this fashion until all the cities are not visited. Find the number of ways in which you can visit all the cities modulo 10^9+7. 

Problem Constraints:
1 <= A <= 1000
1 <= M <= A
1 <= B[i] <= A

Input Format:
The 1st argument given is an integer A, i.e total number of cities.
The 2nd argument given is an integer array B, where B[i] denotes ith city you already visited.

Output Format:
Return an Integer X % (1e9 + 7), the number of ways in which you can visit all the cities.

Example Input:
A = 5
B = [2, 5]

Example Output:
6

Example Explanation:
All possible ways to visit remaining cities are :
1. 1 -> 3 -> 4
2. 1 -> 4 -> 3
3. 3 -> 1 -> 4
4. 3 -> 4 -> 1
5. 4 -> 1 -> 3
6. 4 -> 3 -> 1
*/



#define ll long long
ll fact[1005];
ll f=-1;
ll mod =(int) (1e9+7);
 ll binexpo(ll a, ll b)
   {
       ll ans=1;
       ll k=a;
       for(ll i=0;i<=30;i++)
       {
           if(b&(1<<i))
           {
               ans=(ans*1ll*k)%mod;
           }
           k=(k*1ll*k)%mod;
       }
       return ans;
   }
      ll ncr(ll n, ll r)
   {
        ll d=(fact[n-r]*fact[r])%mod;
        ll tmpans=(binexpo(d,mod-2)*1ll*fact[n])%mod;
        return tmpans;
   }
int Solution::solve(int a, vector<int> &b)
{
    if(f==-1)
    {
    fact[0]=1;
    fact[1]=1;
    for(ll i=2;i<=1000;i++)
    fact[i]=(fact[i-1]*1ll*i)%mod;
    f=1;
    }
   
    ll m=b.size();
    sort(b.begin(), b.end());
    ll p1=b[0]-1;
    ll p2=a-b[m-1];
    vector <ll> parts;
    if(p1!=0)
    parts.push_back(p1);
    if(p2!=0)
    parts.push_back(p2);

    ll ans=1;
    for(ll i=1;i<m;i++)
    {  
       
        if((b[i]-b[i-1]-1)>=1)
        ans= (ans*1ll*binexpo(2,b[i]-b[i-1]-2))%mod;
       
        if((b[i]-b[i-1]-1)>0)
        parts.push_back(b[i]-b[i-1]-1);
    }
    sort(parts.begin(), parts.end());
    reverse(parts.begin(), parts.end());

    ll curr=parts[0];
    for(ll i=1;i<parts.size();i++)
    {
        ll n=curr+1;
        ll r=parts[i];
        ll tmpans=0;
        if(r==0)
        tmpans=1;
        for(int i=1;i<=r;i++)
        {
            tmpans=(tmpans+(ncr(r-1,i-1)*ncr(n,i))%mod)%mod;
        }
        ans=(ans*1ll*tmpans)%mod;
        curr=(curr+parts[i])%mod;
    }
    
    return ans;
}
