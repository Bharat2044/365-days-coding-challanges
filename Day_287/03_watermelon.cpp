// Question Link: https://www.codechef.com/problems/WATMELON


#include<bits/stdc++.h>
using namespace std;
#define f(n) for(int i=0;i<n;i++)
#define mod 1000000007
#define lli long long int 
int main()
{
    lli ttc;
    cin>>ttc;
    while(ttc--)
    {
       lli n,i,sum;
       sum=0;
       cin >> n;
       lli a[n+1];
       for(i=0;i<n;i++)
       {
           cin >> a[i];
       }
       for(i=0;i<n;i++)
       {
           sum += a[i];
       }
       if( sum < 0)
       cout << "NO" << endl;
       else 
       cout << "YES" << endl;
    }
    return 0;
}
