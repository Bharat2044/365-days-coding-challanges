// Question Link: https://www.codechef.com/problems/REDALERT


#include <iostream>
using namespace std;

signed main() {
	// your code goes here
	int t;
	cin>>t;
	
	while(t--){
	    int x,y,z;
	    cin>>x>>y>>z;
	    int a[x];
	    
	    for(int i=0;i<x;i++){
	        cin>>a[i];
	    }
	    
	    int sum=0,flage=0;
	    
	   for(int i=0;i<x;i++){
	      if(a[i]==0){
	           if(sum>=y){
	                sum-=y;
	           }
	           else{
	               sum=0;
	           }
	          
	       }
	       else{
	           sum+=a[i];
	           if(sum>z){
	               flage=1;
	               break;
	           }
	       }
	    }
	    
	    if(flage==1){
	        cout<<"YES"<<endl;
	    }
	    else{
	        cout<<"NO"<<endl;
	    }
	}
	
	return 0;
}
