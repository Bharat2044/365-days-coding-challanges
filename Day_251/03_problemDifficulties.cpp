// Question Link: https://www.codechef.com/problems/PROBDIFF


#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin>>t;
	
	while(t--){
	    int arr[4];
	    for(int i=0;i<4;i++){
	        cin>>arr[i];
	    }
	    
	    sort(arr,arr+4);
	    
	    if(arr[1]!=arr[2] || (arr[1]==arr[2] && arr[2]!=arr[3] && arr[0]!=arr[1])){
	        cout<<2<<endl;
	    }
	    else if(arr[0]==arr[3]){
	        cout<<0<<endl;
	    }
	    else{
	        cout<<1<<endl;
	    }
	}
	
	return 0;
}
