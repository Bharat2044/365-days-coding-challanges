// Question Link: https://www.codechef.com/problems/GMINEQ


#include <bits/stdc++.h>
#define ll long long int
using namespace std;

int main() {
	int t;
	cin>>t;
	
	while(t--)
	{
	    int c1=0,c2=0,n;
	    cin>>n;
	    
	    for(int i=0;i<n;i++){
	        int x;
	        cin>>x;
	        if(x==-1)   c1++;
	        else    c2++;
	    }
	    
	    int mx=max(c1,c2);
	    int mn=min(c1,c2);
	    
	    if(mx&1){
	        if((mx-mn)==1 || (mx-mn)==0)    cout<<"Yes\n";
	        else cout<<"No\n";
	    }
	    else{
	        if((mx-mn)>=0 && (mx-mn)<=2)    cout<<"Yes\n";
	        else    cout<<"No\n";
	    }
	}
	
	return 0;
}
