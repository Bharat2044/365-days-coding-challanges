// Question Link: https://www.codechef.com/problems/FANCY


#include <iostream>
#include<algorithm>
using namespace std;

int main() {
	// your code goes here
	int t;
	cin>>t;
	cin.ignore();
	
	while(t--)
	{
	    string s;
	    getline(cin,s);
	    int flag = 0;
	    int n=s.size();
	    
	    for(int i=0; i<n; i++)
	    {
	        if(s[i]=='n' && s[i+1]=='o' && s[i+2]=='t')
	        {
	            if((i==0 || s[i-1]==' ') && (i==n-3 || s[i+3]==' '))
	            {
	                flag=1;
	            }
	        }
	    }
	    
	    if(flag==1)
	    {
	        cout<<"Real Fancy"<<endl;
	    }
	    else
	    {
	        cout<<"regularly fancy"<<endl;
	    }
	}
	
	return 0;
}
