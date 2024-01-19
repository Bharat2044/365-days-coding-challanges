// Question Link: https://www.codechef.com/problems/GRANAMA


#include <bits/stdc++.h>
using namespace std;

int main() {
	int t; 
	cin>>t;
	
	while(t--){
	    string a,b;
	    cin>>a>>b;
	    
	    multiset<char> h,k;
	    set<char> hh,kk;
	    
	    for(int i=0;i<a.size();i++){
	        h.insert(a[i]);
	        hh.insert(a[i]);
	    }
	    
	    for(int i=0;i<b.size();i++){
	        k.insert(b[i]);
	        kk.insert(b[i]);
	    }
	        
	    if(hh==kk && h!=k) cout<<"NO"<<endl;
	    else cout<<"YES"<<endl;
	}
	
	return 0;
}
