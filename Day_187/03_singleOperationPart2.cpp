// Question Link: https://www.codechef.com/problems/SINGLEOP2


#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	int t;
	cin>>t;
	
	while(t--){
	    int n;
	    cin>>n;
	    
    	string s;
    	cin>>s;
    	int cn=1;
    	
    	for(int i=1;i<n;i++)
    	{
    	    if(s[i]=='0'){
    	        cn++;
    	    }
    	    else{
    	        break;
    	    }
    	 }
    	   
    	 cout<<cn<<endl;
    }

	return 0;
}
