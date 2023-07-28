// Question Link: https://www.codechef.com/problems/MINORMAX


#include <bits/stdc++.h>
using namespace std;

 
int main() {
	// your code goes here
	int test;
	cin>>test;
	
	while(test--) {
	    int n;
	    cin>>n;
	    int arr[n];
	    
	    for(int i=0;i<n;i++)
	        cin>>arr[i];
	    
	    int max1 = -1;
	    int min1 = INT_MAX;
	    int flag = 0;
	    
	    for(int i=0;i<n;i++) {
	        max1 = max(max1,arr[i]);
	        min1 = min(min1,arr[i]);
	        
	        if(max1!= arr[i] && min1!=arr[i]) {
	            flag =1;
	            break;
	        }
	        
	    }
	    
	    if(flag==0)
	        cout<<"YES\n";
	    else
	        cout<<"NO\n";
	}
	
	return 0;
}



