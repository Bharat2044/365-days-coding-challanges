// Question Link: https://www.codechef.com/problems/CHFMOT18


#include <bits/stdc++.h>
using namespace std;

int main()
{
	int t;
	cin >> t;
	
	while (t--)
	{
		int s,n,count=0;
		cin>>s>>n;
		
		if(s%2) 
		    count++,s--;
		    
		while (s)
		{
			count+=(s/n);
			if(s<n)
			{
				count++;
				break;
			}
			s=s%n;
		}
		cout<<count<<endl;						
	}	
	
	return 0; 
}
