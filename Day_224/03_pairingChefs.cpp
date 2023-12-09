// Question Link: https://www.codechef.com/problems/PAIRING


#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	int t;cin>>t;
	while(t--){
	    int n,m;cin>>n>>m;
	    vector<vector<int>>v(m,vector<int>(2));
	    stack<int>s;
	    for(int i=0;i<m;i++)cin>>v[i][0]>>v[i][1];
	    unordered_map<int,int>mp;
	    for(int i=m-1;i>=0;i--){
	        if(mp[v[i][0]]==0&&mp[v[i][1]]==0){
	            mp[v[i][0]]++;mp[v[i][1]]++;
	            s.emplace(i);
	        }
	    }
	    while(!s.empty()){cout<<s.top()<<' ';s.pop();}
	    cout<<endl;
	}
	return 0;
}
