// Question Link: https://www.codechef.com/problems/DOUBLEDDIST


#include<bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	int T;
	cin >> T;
	
	while(T--)
	{
	    int n;
	    cin>>n;
	    int a[n];
	    
	    string flag ="Yes\n";
	    for(int i=0;i<n;i++)
	    {
	        cin>>a[i];
	    }
	    
	    sort(a,a+n);
	    int b[n-1];
	    
	    for(int i=1;i<n;i++)
	    {
	        b[i-1] = a[i]-a[i-1];
	    }
	    
	    for(int i=1;i<n-1;i++)
	    {
	        if(b[i-1]*2!=b[i]&&b[i]*2!=b[i-1])
	        {
	            flag ="NO\n";
	            break;
	        }
	    }
	    
	    cout<<flag;
	}
	
	return 0;
}
