// Question Link: https://www.codechef.com/problems/COOMILK


#include <bits/stdc++.h>
using namespace std;

int main()
{
	int T;
	cin>>T;
	while(T--)
	{
	    int n; cin>>n;
	    string str[n];
	    bool flag=1;
	    for(int i=0;i<n;i++)
	    {
	        cin>>str[i];
	    }
	    if(n==1 && str[0]=="cookie")
	    flag=false;
	    else if(str[n-1]=="cookie")
	    flag=false;
	    else
	    {
	        for(int i=0;i<n-1;i++)
	        {
	            if(str[i]=="cookie" && str[i+1]=="cookie")
	            {
	                flag=false;
	                break;
	            }
	        }
	    }
	    if(flag)  cout<<"YES"<<endl;
	    else  cout<<"NO"<<endl;
	}
	return 0;
}
