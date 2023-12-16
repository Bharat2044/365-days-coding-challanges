// Question Link: https://www.codechef.com/problems/MAKEZERO


#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	int t;
	cin>>t;
	
	for(int i=0; i<t; i++)
	{
	    int n;
	    cin>>n;
	    
	    vector<int> v(32,0);
	    int count=0;
	    
	    for(int j=0; j<n; j++)
	    {
	        int a;
	        cin>>a;
	        
	        for(int k=0; k<32; k++)
	        {
	            if((a>>k)&1) 
	                v[k]++;
	        }
	    }
	    
        for(auto it: v)
        {
            if(it!=0) 
            {
                count++;
            }
        }
	    cout<<count<<endl;
	}
	
	return 0;
}
