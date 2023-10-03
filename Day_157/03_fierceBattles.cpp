// Question Link: https://www.codechef.com/problems/DRGNBOOL


#include <iostream>
using namespace std;

int main() {
	// your code goes here
	int t;
	cin>>t;
	
	while(t--){
	    int x,y;
	    cin>>x>>y;
	    
	    int a[101]={0},b[101]={0};
	    
	    for(int i=0;i<x;i++){
	        int p,l;
	        cin>>p>>l;
	        a[l]+=p;
	    }
	    
	    for(int i=0;i<y;i++){
	        int p,l;
	        cin>>p>>l;
	        b[l]+=p;
	    }
	    
	    int sum=0;
	    for(int i=0;i<101;i++){
	       if(a[i]<b[i]) {
	           sum+=(b[i]-a[i]);
	       }
	    }
	    
	    cout<<sum<<endl;
	}
	
	return 0;
}
