// Question Link: https://www.codechef.com/problems/ABOVEAVG


#include <iostream>
using namespace std;
#define int long long 

signed main() {
	// your code goes here
	int t;
	cin>>t;
	
	while(t--){
	    int x,y,z;
	    cin>>x>>y>>z;
	    
	    if(y<=z){
	        cout<<0<<endl;
	    }
	    else{
	         int a = x*z;
    	     int b = a/(z+1);
    	     cout<<b<<endl;
	    }	    
	}
	
	return 0;
}
