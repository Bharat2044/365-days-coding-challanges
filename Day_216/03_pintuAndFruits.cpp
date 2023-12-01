// Question Link: https://www.codechef.com/problems/CHPINTU


#include <bits/stdc++.h>
using namespace std;
 
int main() {
	// your code goes here
	int test;
	cin>>test;
	
	while(test--)
	{
	    int n,m1;
	    cin>>n>>m1;
	    
	    int f[n];
	    int p[n];
	    
	    for(int i=0;i<n;i++)
	    {
	        cin>>f[i]; 
	    }
	    
	    for(int i =0;i<n;i++)
	    {
	        cin>>p[i];
	    }
	    
	    map<int,int> m;
	    for(int i=0;i<n;i++)
	    {
	        m[f[i]] +=p[i];
	    }
	    
	    int min = INT_MAX;
	    for(auto p : m )
	    {
	        if(p.second<min)
	        {
	            min=p.second;
	        }
	    }
	    cout<<min<<endl;
	}
	
	return 0;
}




