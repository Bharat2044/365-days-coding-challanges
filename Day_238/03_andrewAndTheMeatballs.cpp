// Question Link: https://www.codechef.com/problems/AMMEAT


#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main() {
	ll t;
	cin >> t;
	
	while(t--){
	    ll n,m;
	    cin >> n >> m;
	    ll a[n];
	    
	    for(ll i = 0ll;i<n;i++)
	     cin >> a[i];
	     
	    sort(a,a+n,greater<ll>());
	    
	    ll sum = 0ll;
	    ll i = 0ll;
	    ll flag = 0ll;
	    
	    if(m == 0)
	     cout << "0" << endl;
	    else{
    	    while(i < n ){
    	        sum  = sum + a[i];
    	        i++;
    	        if(sum >= m)
    	         {
    	             flag = 1ll;
    	             break;
    	         }
    	    }
    	    
    	    if(flag)
    	        cout << i << "\n";
    	    else
    	        cout << "-1\n";
	     }
	    
	}
	
	return 0;
}
