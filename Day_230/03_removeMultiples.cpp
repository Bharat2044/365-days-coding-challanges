// Question Link: https://www.codechef.com/problems/REMOVEMUL


#include <iostream>
using namespace std;

int main() {
	int t;
	cin>>t;
	
	while(t--){
	    int l=0;
	    long long int n,k,sum=0,mum=0,pum=0;
	    
	    cin>>n>>k;
	    long long int h[k];
	    
	    for(int i=0;i<k;i++){
	        cin>>h[i];
	        
	        mum+=h[i];
	       }
	       sum+=(n*(n+1))/2;
	      
	        cout<<sum-mum<<endl;

	    }
	    
	return 0;
}
