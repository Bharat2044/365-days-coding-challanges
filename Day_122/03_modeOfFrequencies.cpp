// Question Link: https://www.codechef.com/problems/MODEFREQ


#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--)
	{
	    int n,mx=INT_MIN,mn=INT_MAX,count=0;
	    cin>>n;
	    
	    map<int,int> m; 
	    vector<int> v(n);
	    
	    for(int i=0;i<n;i++){
	        cin>>v[i];  //inserting values in vector
	        m[v[i]]++;  //inserted the element in map for frequency
	    }
	    
	    map<int,int> m1; // checking how many elem has m[i] frequency
	    
	   for(auto x:m)
	        m1[x.second]++; //inserting frequency of m in map m1
	        
	    for(auto x: m1) //finding mode in m1
	        mx=max(x.second,mx);
	    
	    for(auto x:m1){ //if their are 2 max mode or to find the value of max mode 
	        if(x.second==mx)
	            mn=min(x.first,mn);//to find what value the mx has
	    }
	    cout<<mn<<endl;
	    
	}
	return 0;
}
