// Question Link: https://www.codechef.com/problems/SANTACHOC


#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin>>t;
	
	while(t--){
	    int n, k;
	    cin>>n>>k;
	    vector<int> v(n);
	    
	    for(int i=0; i<n; i++){
	        cin>>v[i];
	    }
	    
	    int sum=0;
	    for(int i=0; i<n; i++){
	        sum+=v[i];
	    }
	    
	    if(sum<n){
	        cout<<"NO"<<endl;
	    }
	    else{
	        if(sum%n!=0 && k==0){
	            cout<<"NO"<<endl;
	        }
	        else{
	            cout<<"YES"<<endl;
	        }
	    }
	}
	
	return 0;
}
