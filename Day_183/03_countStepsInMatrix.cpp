// Question Link: https://www.codechef.com/problems/MSTEP


#include <iostream>
using namespace std;
#include<bits/stdc++.h>
#define ll long long
#define TEST int t;cin>>t;while(t--)

int main() {
	TEST{
	    int n;cin>>n;
	    unordered_map<int,pair<int,int>>ump;
	    for(int i=1;i<=n;i++){
	        for(int j=1;j<=n;j++){
	            int val;cin>>val;
	            ump[val]=make_pair(i,j);
	        }
	    }
	    int res=1,step=0;
	    while(res!=n*n){
	        pair<int,int>p1=ump[res];
	        pair<int,int>p2=ump[res+1];
	        step+=abs(p1.first-p2.first)+abs(p1.second-p2.second);
	        res++;
	    }
	    cout<<step<<endl;

	}
	
	return 0;
}
