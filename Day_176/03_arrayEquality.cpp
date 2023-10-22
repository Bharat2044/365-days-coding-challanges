// Question Link: https://www.codechef.com/problems/ARREQU


#include <iostream>
#include <map>
using namespace std;

int main() {
	// your code goes here
	long long t; 
	cin>>t;
	
	while(t--){
	    long long n;
	    cin>>n;
	    
	    long long a[n];
	    long long c = n - (n/2);
	    map<int,int>mp;
	    
	    for(long long i=0;i<n;i++){
	        cin>>a[i];
	        mp[a[i]]++;
	    }
	    
	    int flag=1;
	    for(auto i:mp){
	        if(i.second > c){
	            flag=0;
	            break;
	        }
	    }
	    
	    if(flag==0) 
	        cout<<"NO\n";
	    else 
	        cout<<"YES\n";
	}
	
	return 0;
}
