// Question Link: https://www.codechef.com/problems/CHEFSTON


#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin>>t;
	
	while(t--){
	    long long n,k;
	    cin>>n>>k;
	    long long A[n],B[n],ans[n];
	    
	    for(int i=0;i<n;i++){
	        cin>>A[i];
	    }
	    for(int i=0;i<n;i++){
	        cin>>B[i];
	    }
	    
	    for(int i=0;i<n;i++){
	        ans[i]=k/A[i]*B[i];
	    }
	    
	    sort(ans,ans+n);
	    cout<<ans[n-1]<<endl;
	}
	
	return 0;
}
