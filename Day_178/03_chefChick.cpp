// Question Link: https://www.codechef.com/problems/CHFCHK


#include<bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	int t;
	cin>>t;
	
	while(t--)
	{
	    int n;
	    cin>>n;
	    int a[n];
	    
	    for(int i=0;i<n;i++)
	    {
	        cin>>a[i];
	    }
	    
	    sort(a,a+n);
	    cout<<a[0]<<endl;
	}
	
	return 0;
}
