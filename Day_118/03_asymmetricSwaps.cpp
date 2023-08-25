// Question Link: https://www.codechef.com/problems/ARRSWAP


#include <bits/stdc++.h>
using namespace std;
#define int long long 

signed main() {
	// your code goes here
	int t;
	cin>>t;
	
	while(t--){
	    int x;
	    cin>>x;
	    
	    int a = 2*x;
	    int sum1=0,sum2=0;
	    int arr[2*x];
	    
	    for(int i=0;i<a;i++){
	        cin>>arr[i];
	    }
	    
	    sort(arr,arr+a);
	    int ans = 1e9;
	    
	    for(int i=0;i<=x;i++){
	        ans = min(ans,arr[x+i-1]-arr[i]);
	    }
	    
	    cout<<ans<<endl;
	}
	
	return 0;
}
