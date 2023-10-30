// Question Link: https://www.codechef.com/problems/SUMPERM


#include<bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin>>t;
	
	while(t--)
	{
	    int a;
	    cin>>a;
	    vector<int>v;
	    if(a%2==0)
	    {
	        for(int i=1;i<=a;i++)
	        {
	            if(i%2!=0)
	            {
	                v.push_back(i+1);
	            }
	            else
	            {
	                v.push_back(i-1);
	            }
	       }
	       for(int i=0;i<a;i++)
	       {
	           cout<<v[i]<<" ";
	       }
	    }
	     else
	     {
	         cout<<"-1"<<endl;
	     }
	     cout<<endl;
	 }
	 
	return 0;
}
