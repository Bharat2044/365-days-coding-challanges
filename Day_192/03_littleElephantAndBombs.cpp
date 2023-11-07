// Question Link: https://www.codechef.com/problems/LEBOMBS


#include <iostream>
using namespace std;

int main() {
	// your code goes here
	int t,N;
	cin>>t;
	
	while(t--)
	{
	  cin>>N;
	  string s;
	  cin>>s;
	  
	  if(s[0]=='1')
	  {
	    s[0]='2';
	    if(s[1]!='1')
	      s[1]='2';
	  }
	  
	  if(s[N-1]=='1')
	  {
	    s[N-1]='2';
	    if(s[N-2]!='1')
	      s[N-2]='2';
	  }
	  
	  for(int i=1;i<(N-1);i++)
	  {
	    if(s[i]=='1')
	    {
	      s[i]='2';
	      if(s[i-1]!='1')
	        s[i-1]='2';
	        
	      if(s[i+1]!='1')
	        s[i+1]='2';
	    }
	  }
	  
	  int c=0;
	  for(int i=0;i<N;i++)
	  {
	    if(s[i]=='0')
	      c++;
	  }
	  
	  cout << c << endl;
	}
	
	return 0;
}
