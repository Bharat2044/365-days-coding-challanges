// Question Link: https://www.codechef.com/problems/CATFEED


#include <bits/stdc++.h>
using namespace std;

int main() 
{
	int t;
	cin>>t;
	
	while(t--) 
	{
	    int n,m;
	    cin>>n>>m;
	    int cnt[n+1];
	    
	    for(int i=0;i<=n;i++)
	    {
	        cnt[i]=0;
	    }
	    
	    int a[m+1];
	    int ans=0;
	    
	    for(int i=1;i<=m;i++)
	    {
	        cin>>a[i];
	        cnt[a[i]]++;
	        
	        if(i%n==0) {
	            if( (i/n)<cnt[a[i]] ) {
	                ans++;
	            }
	        }
	        else {
	            if( ((i/n)+1)<cnt[a[i]] ) {
	                ans++;
	            }
	        }
	    }
	    
	    if(ans==0)
	        cout<<"YES"<<endl;
	    else
	        cout<<"NO"<<endl;
	}
	
	return 0;
}
