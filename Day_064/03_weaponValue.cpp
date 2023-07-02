// Question Link: https://www.codechef.com/problems/SC31


#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--){
	    int x;
	    cin>>x;
	    
	    string r="";
	    int count=0;
	    
	    map<char,int>mp;
	    string s;
	     
	    for(int i=0;i<x;i++){
	        cin>>s;
	        r+=s;
	    }
	    
	    for(int i=0;i<r.size();i++){
	        if(r[i]=='1'){
	         int c = i%10;
	         mp[c]++; 
	        }   
	    }
	    
	    for(auto i : mp){
	        int a = i.second;
	        if(a%2==1){
	            count++;
	        }
	    }
	   cout<<count<<endl;
	}
	
	return 0;
}
