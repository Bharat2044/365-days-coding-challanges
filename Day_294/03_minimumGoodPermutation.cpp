// Question Link: https://www.codechef.com/problems/MINPERM


#include <iostream>
using namespace std;

int main() {
	int t;
	cin>>t;
	
	while(t--){
	    int n;
	    cin>>n;
	    
	    if(n%2 == 0){
	        for(int i=1;i<=n;i+=2){
	            cout<<i+1<<" ";
	            cout<<i<<" ";
	        }
	        cout<<endl;
	    }
	    else if(n%2 != 0){
	        if(n == 1){
	            cout<<1<<endl;
	        }
	        else{
	            for(int i=1;i<=n;i+=2){
    	            if(i+2 == n){
    	                cout<<i+1<<" ";
    	                cout<<i+2<<" ";
    	                cout<<i<<endl;
    	            }
    	            else if(i+2 != n && i+2 < n){
    	                cout<<i+1<<" ";
    	                cout<<i<<" ";
    	            }
    	        }
    	    }
	    }
	}
	
	return 0;
}
