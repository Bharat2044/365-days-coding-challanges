// Question Link: https://www.codechef.com/problems/FRGTNLNG


#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	int test;
	cin>>test;
	
	while(test--)
	{
	    int n,k;
	    cin>>n>>k;
	    
	    map<string , int> mp;
	    string str[n];
	    
	    for(int i =0;i<n;i++)
	    {
	        cin>>str[i];
	        mp[str[i]]=0;
	    }
	    
	    for(int i =0;i<k;i++)
	    {
	        int l;
	        cin>>l;
	        
	        for(int j=0;j<l;j++)
	        {
	            string ph;
	            cin>>ph;
	            mp[ph]=1;
	        }
	    }
	    
	    for(auto p : str)
	    {
	        if(mp[p]!=0){
	            cout<<"YES ";
	        }
	        else{
	            cout<<"NO ";
	        }
	    }
	    cout<<endl;
	}
	
	return 0;
}



