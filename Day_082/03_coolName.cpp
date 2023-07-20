// Question Link: https://www.codechef.com/problems/CALPOWER


#include <iostream>
#include<bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	int t;
	cin>>t;
	
	while(t--){
	    string s;
	    int arr[101],tot=0,q;
	    cin>>s;
	    
	    for(int i=0;i<s.size();i++){
	        q=s[i]-96;
	        arr[i]=q;
	    }
	    
	    sort(arr,arr+s.size());
	    for(int i=0;i<s.size();i++)
	        tot = tot + ((i+1) * arr[i]);
	    
	    cout<<tot<<endl;
	}
	
	return 0;
}
