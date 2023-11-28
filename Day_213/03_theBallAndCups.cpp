// Question Link: https://www.codechef.com/problems/TAVISUAL


#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	int t;
	cin>>t;
	
	while(t--)
	{
	    int n,c,q;
	    cin>>n>>c>>q;
	    int l,r;
	
	    for(int j=0;j<q;j++)
	    {
	        cin>>l>>r;
	        if(c>=l&&c<=r)
	        {
	            c=r-c+l;
	        }
	    }
	
	    cout<<c<<endl;
	}
	
	return 0;
}
