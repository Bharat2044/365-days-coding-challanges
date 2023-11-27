// Question Link: https://www.codechef.com/problems/CHEFLUCK


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
	    int j;
	    
	    for(j=n; j>=0; j-=4)
	    {
	        if(j%7==0)
	        {
	            cout<<j<<endl;
	            break;
	        }
	    }
	    
	    if(j<0)
	    {
	        cout<<"-1"<<endl;
	    }
	}
	
	return 0;
}
