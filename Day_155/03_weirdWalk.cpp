// Question Link: https://www.codechef.com/problems/WWALK


#include <iostream>
using namespace std;
#define int long long 

signed main() {
	// your code goes here
	int t;
	cin>>t;
	
	while(t--){
	    int x;
	    cin>>x;
	    int a[x],b[x];
	    
	    for(int i=0;i<x;i++){
	        cin>>a[i];
	    }
	    
	    for(int i=0;i<x;i++){
	        cin>>b[i];
	    }
	    
	    int A=0,B=0,ans=0;
	    for(int i=0;i<x;i++){
	        if(a[i]==b[i] and A==B){
	            ans+=a[i];
	        }
	        else{
	            A+=a[i];
	            B+=b[i];
	        }
	    }
	    cout<<ans<<endl;
	}
	
	return 0;
}
