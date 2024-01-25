// Question Link: https://www.codechef.com/problems/SUMOFPROD1


#include<bits/stdc++.h>
#define ll long long int 
using namespace std;

int main() {
	// your code goes here
	ll t;cin>>t;
	while(t--){
	    int n; cin>>n;
	    long int k=0,s=0;
	    vector<long int>vec;
	    int a[n];
	    for(int i=0;i<n;i++)  cin>>a[i];
	    for(int i=0;i<n;i++){ 
	        if(a[i]==1) s++;
	        else{ 
	            k+=((s*(s+1))/2);
	            s=0;
	        }
	    }
	    k+=((s*(s+1))/2);
	    cout<<k<<endl;
	}
	return 0;
}
