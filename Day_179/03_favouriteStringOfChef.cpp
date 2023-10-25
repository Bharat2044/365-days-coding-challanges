// Question Link: https://www.codechef.com/problems/CHEFFAV


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
	    string s;
	    cin>>s;
	    
	    int count=0;
	    int l=s.length();
	    
	    for(int i=0;i<n-3;i++)
	    {
	        if(s[i]=='c' and s[i+1]=='o' and s[i+2]=='d' and s[i+3]=='e')
	        {
	            l=i;
	        }
	        else if(s[i]=='c' and s[i+1]=='h' and s[i+2]=='e' and s[i+3]=='f')
	        {
	            count=i;
	            break;
	        }
	    }
	    
	    if(l>count)
	    {
	        cout<<"WA\n";
	    }
	    else 
	    {
	        cout<<"AC\n";
	    }
	}
	
	return 0;
}
