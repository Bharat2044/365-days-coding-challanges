// Question Link: https://www.codechef.com/problems/PROC18B


#include<bits/stdc++.h>
#define ll long int
using namespace std;

int main() {
	// your code goes here
	int t;
	cin>>t;
	
	while(t--){
	    ll n;
	    cin>>n;
	    double a[n];
	    
	    for(ll i=0;i<n;i++){
	        cin>>a[i];
	    }
	    
	    sort(a,a+n);
	    double d=(a[n-1]+a[n-2])/2;
	    
	     for(ll i=n-3;i>=0;i--){
	       d=(d+a[i])/2;
	    }
	    
	    cout<<fixed<<setprecision(8)<<d<<endl;
	}
	
	return 0;
}
