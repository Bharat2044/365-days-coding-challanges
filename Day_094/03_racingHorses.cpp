// Question Link: https://www.codechef.com/problems/HORSES


#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin>>t;
	
	while(t--){
	    int n;
	    cin>>n;
	    
	    long int arr[n];
	    for(int i=0;i<n;i++)
	        cin>>arr[i];
	    
	    sort(arr,arr+n);
	    long int min=1000000000;
	    
	    for(int i=1;i<n;i++){
	        if(arr[i]-arr[i-1]<min)
	            min=arr[i]-arr[i-1];
	    }
	    
	    cout<<min<<endl;
	}
	
	return 0;
}
