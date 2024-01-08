// Question Link: https://www.codechef.com/problems/MAKE_AB_SAME


#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
	// your code goes herei
	int t;
	cin>>t;
	
	while(t--)
	{
	    ll n;
	    cin>>n;
	    ll i,a[n],b[n],o=0;
	    
	    for(i=0;i<n;i++)
	    {
	        cin>>a[i];

	        if(a[i]==1)
	            o++;
	    }
	    
	    for(i=0;i<n;i++)
	        cin>>b[i];
	    
	    ll c=0;
	    for(i=0;i<n;i++)
	    {
	        if(a[i]!=b[i])
	        {
	            if(i==0 || i==n-1)
	            {
	                c=1;
	                break;
	            }
	            else if(a[i]==1)
	            {
	                c=1;
	                break;
	            }
	            else
	            {
	                if(o==0)
	                {
	                    c=1;
	                    break;
	                }
	                else
	                    a[i]=1;
	            }
	        }
	        
	    }
	    
	    if(c==0)
	        cout<<"YES"<<endl;
	    else
	        cout<<"NO"<<endl;
	}
	
	return 0;
}
