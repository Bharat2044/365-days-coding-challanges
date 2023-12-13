// Question Link: https://www.codechef.com/problems/CHCUBE


#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	int t;
	cin>>t;
	
	while(t--){
	    string arr[6];
	    unordered_map<string,int> m;
	    
	    for(int i=0;i<6;i++){
	        cin>>arr[i];
	        m[arr[i]]++;
	    }
	    
	    bool ans = false;
	    for(auto &itr: m){
	        if(itr.second>=3){
	            string s = itr.first;
	            if( (arr[0]==s || arr[1]==s) && (arr[2]==s || arr[3]==s) && (arr[4]==s || arr[5]==s) ){
	                ans =true;
	            }
	        }
	    }
	    
	    if(ans)cout<<"YES"<<endl;
	    else cout<<"NO"<<endl;
	}
	
	return 0;
}
