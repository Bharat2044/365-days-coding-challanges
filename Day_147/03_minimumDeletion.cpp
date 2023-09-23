// Question Link: https://www.codechef.com/problems/RD19


#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin>>t;
	
	while(t--)
	{
	    int n;
	    cin>>n;
	    int a[n];
	    
	    for(int i = 0;i<n;i++)
	    cin>>a[i];
	    
	    int check = 0;
	    
	    for(int i = 0;i<n;i++)
	    {
	        for(int j = i;j<n;j++)
	        {
	            if(gcd(a[i],a[j]) == 1)
	            {
	                    check =1;
	            break;
	            }
	        }
	        
	        if(check == 1)
	           break;
	    }
	    
	    if(check)
	        cout<<0<<endl;
	    else
	        cout<<-1<<endl;
	}
	
	return 0;
}
