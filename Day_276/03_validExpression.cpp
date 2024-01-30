// Question Link: https://www.codechef.com/problems/EVALMAS


#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
	// your code goes herei
	int t;
	cin>>t;
	
	while(t--)
	{
	    ll n,x;
	    cin>>n>>x;
	    
	    ll m1,m2,i;
	    m1=-(n-1);
	    m2=n+1;
	    string s;
	    
	    if(x<m1 || x>m2)
	    {
	        cout<<"-1";
	    }
	    else 
	    {
	        if(x<1)
	        {
	            ll c1=x-m1;
	            for(i=0;i<c1;i++)
	            {
	                cout<<"*";
	            }
	            for(i=c1;i<n;i++)
	            {
	                cout<<"-";
	            }
	        }
	        else
	        {
	            ll c=m2-x;
	            for(i=0;i<c;i++)
	            {
	                cout<<"*";
	            }
	            for(i=c;i<n;i++)
	            {
	                cout<<"+";
	            }
	        }
	    }
	    cout<<endl;
	}
	
	return 0;
}
