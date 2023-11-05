// Question Link: https://www.codechef.com/problems/MAXFUN


#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	int t;
	cin>>t;
	
	while(t--)
	{
	    int n;
	    cin>>n;
	    long arr[n];
	    
	    for(int i=0;i<n;i++)
	    {
	        cin>>arr[i];
	    }
	    
	    long maxi = arr[0];
	    long mini = arr[0];
	    
	    for(int i=1;i<n;i++)
	    {
	        maxi = max(maxi, arr[i]);
	        mini = min(mini, arr[i]);
	    }
	   
	    cout<<(2*(maxi - mini))<<endl;
	}
	
	return 0;
}
