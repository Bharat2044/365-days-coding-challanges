// Question Link: https://www.codechef.com/problems/EVMHACK


#include <iostream>
using namespace std;

int main() {
	// your code goes here
	int t;
	cin>>t;
	
	while(t--){
	    double a,b,c,p,q,r;
	    cin>>a>>b>>c>>p>>q>>r;
	    
	    double x=(p+q+r)/2;
	    if(p+b+c>x || a+q+c>x|| a+b+r>x || a+b+c>x )
	        cout<<"Yes"<<endl;
	    else
	        cout<<"No"<<endl;
	}
	
	return 0;
}
