// Question Link: https://www.codechef.com/problems/SRTO3


#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;

void sortMe(ll arr[], ll first, ll last){
    sort(arr+first, arr+last+1);
    // for(int i = first; i <= last; i++){
    //     cout<<arr[i]<<" ";
    // }
    // cout<<endl;
}

int main() {
	// your code goes here
	ll t; cin>>t;
	while(t--){
	   // Getting all inputs
	    ll n, m; cin>>n>>m;
	    ll A[n], B[m];
	    for(ll i = 0; i < n; i++) cin>>A[i];
	    for(ll i = 0; i < m; i++) cin>>B[i];
	    
	   // Finding max element in array B, to minimize total number of sorting loops.
	   ll maxEle = *max_element(B, B + m);
	   
       sortMe(A, n-maxEle, n-1);
	   
	   //print sorted array;
	   for(ll i = 0; i < n; i++){
	       cout<<A[i]<<" ";
	   }
	   cout<<endl;
	}

}
