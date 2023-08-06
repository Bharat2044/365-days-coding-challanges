// Question Link: https://www.codechef.com/problems/CLOSEVOWEL


#include <bits/stdc++.h>
using namespace std;

int isVowel(char V)
{
  if(V=='a'||V=='e'||V=='i'||V=='o'||V=='u')
    return 1;
  else
    return 0;
}

int main() {
	// your code goes here
	int t,N;
	cin>>t;
	
	while(t--)
	{
	  cin>>N;
	  string s;
	  cin>>s;
	  
	  int total=1,m=pow(10,9)+7;
	  for(int i=0;i<N;i++)
	  {
	    
	    if(!isVowel(s[i]))
	    {
	      int a1=0,b1=0;
	      char a,b;
	      a=b=s[i];
	      while(a>'a')
	      {
	        a-=1;
	        a1++;
	        if(isVowel(a))
	          break;
	       }
	       while(b<'z')
	       {
	        b+=1;
	        b1++;
	        if(isVowel(b))
	          break;
	        }
	        if(a1==b1)
	          total=(total*2)%m;
	     }
	  }
	  
	  cout << total << std::endl;
	}
	
	return 0;
}
