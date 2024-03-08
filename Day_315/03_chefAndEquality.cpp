// Question Link: https://www.codechef.com/problems/CHEFEQ


#include <bits/stdc++.h>
using namespace std;

 
int main() {
	// your code goes here
	int test;
	cin>>test;
	
	while(test--) {
	    int n;
	    cin>>n;
	    
	    map<int,int> mp;
	    int max_count = INT_MIN;
	    
	    for(int i=0;i<n;i++) {
	        int x;
	        cin>>x;
	        mp[x]++;
	        max_count = max(max_count,mp[x]);
	    }
	    
	    cout<<n-max_count<<endl;
	}
	
	return 0;
}



