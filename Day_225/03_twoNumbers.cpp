// Question Link: https://www.codechef.com/problems/TWONMS


#include <bits/stdc++.h>
using namespace std;
#define ll long long 

int main() {
	// your code goes here
	int t;
	cin>>t;
	
	while(t--)
	{
	    ll a, b, n;
	    cin>>a>>b>>n;
	    
	    if(n%2==1)  
	        a*=2;
	    
	    cout<<max(a, b)/min(a, b)<<"\n";
	}
	
	return 0;
}
