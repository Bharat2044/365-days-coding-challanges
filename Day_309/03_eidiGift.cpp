// Question Link: https://www.codechef.com/problems/EID2


#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	int t;
	cin>>t;
	
	while(t--) {
	    int a[3],c[3];
	    map<int,int>mp;
	    
	   cin>>a[0]>>a[1]>>a[2];
	   cin>>c[0]>>c[1]>>c[2];
	   
	   mp[a[0]]=c[0];
	   mp[a[1]]=c[1];
	   mp[a[2]]=c[2];
	   int fl=1;
	   
	   for(int i=0;i<3-1;i++) {
	       for(int j=0;j<3-i-1;j++) {
	           if(a[j]>a[j+1]) {
	               swap(a[j],a[j+1]);
	               swap(c[j],c[j+1]);
	           }
	       }
	   }
	   
	   for(int i=0;i<2;i++) {
	       if(a[i]==a[i+1]){
	           if(c[i]!=c[i+1])
	               fl=0;
	           
	       }
	       else if(a[i]<a[i+1]) {
	           if(c[i]>=c[i+1])
	               fl=0;
	       }
	   }
	    
	    if(fl==0)
	        cout<<"NOT FAIR"<<endl;
	    else
	        cout<<"FAIR"<<endl;
	}
	
    return 0;
}
