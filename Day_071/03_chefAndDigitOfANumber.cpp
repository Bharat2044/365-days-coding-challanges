// Question Link: https://www.codechef.com/problems/LONGSEQ


#include <iostream>
#include<bits/stdc++.h>
#include<string>
using namespace std;

int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--)
	{
	   string s;
	   cin>>s;
	   int x=0;
	   int y=0;
	   
	   for(int i=0;i< s.length();i++)
	   {
	       if(s[i]=='1')
	       {
	           x++;
	       }
	       else
	       {
	           y++;
	       }
	   }
	   if(x==1 or y==1)
	   {
	       cout<<"Yes\n";
	   }
	   else
	   {
	       cout<<"No\n";
	   }
	   
	}
	return 0;
}
