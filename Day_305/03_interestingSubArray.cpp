// Question Link: https://www.codechef.com/problems/SUBARRY


#include<bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	int t;
	cin >> t;
	
	while(t--)
	{
	    long long n;
	    cin >> n;
	    
	    long long A[n];
	    for(int i=0; i<n; i++)
	    {
	        cin >> A[i];
	    }
	    
	    long long max=0, min=0;
	    sort(A, A+n);
	    
	    if(A[0]<0 && A[n-1]>0)
	    {
	        if(-1*A[0] > A[n-1])
	        {
	            max = A[0]*A[0];
	        }
	        else
	        {
	            max = A[n-1]*A[n-1];
	        }
	        
	        min = A[0]*A[n-1];
	    }
	    else if(A[0]<0 && A[n-1]<0)
	    {
	        max = A[0]*A[0];
	        min = A[n-1]*A[n-1];
	    }
	    else
	    {
	        max = A[n-1]*A[n-1];
	        min = A[0]*A[0];
	    }
	    
	    cout << min << " " << max << endl;
	}
	
	return 0;
}
