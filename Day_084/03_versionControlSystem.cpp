// Question Link: https://www.codechef.com/problems/VCS?tab=statement


#include <iostream>
#include<unordered_map>
using namespace std;

int main() {
	// your code goes here
	int t;
	cin>>t;
	
	while(t--){
	    int n,m,k,val;
	    cin>>n>>m>>k;
	    
	    unordered_map<int,int> mp;
	    for(int i=0;i<(m+k);i++){
	        cin>>val;
	        mp[val]++;
	    }
	   
	    int x=0,y=0;
	    
	    for(auto i:mp){
	        if(i.second>1)
	            x++;
	        for(int j=1;j<=n;j++)
	            if(i.first==j)
	                y++;
	    }
	    
	    cout<<x<<" "<<n-y<<endl;
	    
	}
	
	return 0;
}
