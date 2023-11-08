// Question Link: https://www.codechef.com/problems/LEPERMUT


#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin>>t;
	
	while(t--){
	    int n;
	    cin>>n;
	    long int arr[n],cnt=0,sum=0;
	    
	    for(int i=0;i<n;i++){
	        cin>>arr[i];
	    }
	     
	    for(int i=1;i<n;i++){
	         if(arr[i]<arr[i-1]){
	             sum++;
	         }
	     }
	     
	     for(int i=0;i<n-1;i++){
	         for(int j=i+1;j<n;j++){
	             if(arr[i]>arr[j]){
	                 cnt++;
	             }
	         }
	     }
	     
	     if(cnt==sum){
	         cout<<"YES"<<endl;
	     }
	     else{
	         cout<<"NO"<<endl;
	     }
	}
	
	return 0;
}
