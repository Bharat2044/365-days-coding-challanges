// Question Link: https://www.codechef.com/problems/LOSTSEQ


#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin>>t;
	
	while(t--) {
	    int n;
	    cin>>n;
	    
	    int a[2*n];
	    int sum =0;
	    
	    for(int i=0; i<(2*n); i++) {
	        cin>>a[i];
	        sum+=a[i];
	    }
	    
	    if(sum%2) 
	        cout<<"NO"<<endl;
	    else 
	        cout<<"YES"<<endl;
	}
	
	return 0;
}
