// Question Link: https://www.codechef.com/problems/SUSSTR


#include <iostream>
#include<string>
using namespace std;

int main() {
	// your code goes here
	int t;
	cin>>t;
	
	while(t--)
	{
	    int n,e=0;
	    cin>>n;
	    string s;
	    cin>>s;
	    
	    string t;
	    if(n%2==0)e=1;
	    
	    for(int i=0;i<n/2;i++)
	    {
	        if(s[i]=='0')
	            t.insert(0,"0");
	        else
	            t=t+'1';
	        int k=n-1-i;
	        if(s[k]=='0')
	           t=t+'0'; 
	        else
	            t.insert(0,"1");
	    }
	    
	    if(e==0)
	    {
	        int i=(n-1)/2;
	        if(s[i]=='0')
	           t.insert(0,"0");
	        
	        else
	        
	            t=t+'1';
	    }
	    
	    cout<<t<<endl;
	}
	
	return 0;
}
