// Question Link: https://www.codechef.com/problems/CBARG


#include<bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	int t;
	cin>>t;
	
	while(t--){
	    int n;
	    cin>>n;
	    int a[n];
	    
	    for(int i=0;i<n;i++){
	        cin>>a[i];
	    }
	    
	    long int sum=a[0];
	  
        for(long int  i=0;i<n-1;i++){
	       if(a[i+1]>a[i]){
	           sum+=a[i+1]-a[i];
	       }
	    }
	    cout<<sum<<endl;
	}
	
	return 0;
}
