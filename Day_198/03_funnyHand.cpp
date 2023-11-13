// Question Link: https://www.codechef.com/problems/FUNHAND


#include <iostream>
using namespace std;

int main() {
	// your code goes here
	int t  ; 
	cin>>t;
	
	while(t--){
	    long int n , a, b ; 
	    cin>>n>>a>>b; 
	    
	    long int x = min(a , b);
	    long int y = max(a, b);
	    
    	if(abs(a-b)==2) 
    	    cout<<1<<endl;
    	else if (abs(a-b)==1) {
    	    if(x==1 ||y==n ) 
    	        cout<<1<<endl;
    	    else 
    	        cout<<2<<endl;
    	}
    	else 
    	    cout<<0<<endl;
	}
	
	return 0;
}
