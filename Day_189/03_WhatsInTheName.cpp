// Question Link: https://www.codechef.com/problems/NITIKA


#include <bits/stdc++.h>
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
	  string word="",y[3];
	  int i=0;
	  
	  for(auto x:s)
	  {
	    if(x==' ')
	    {
	      y[i]=word;
	      word="";
	      i++;
	    }
	    else
	    {
	      word=word+x;
	    }
	  }
	  y[i]=word;
	  
	 if(!y[0].empty() && y[1].empty() && y[2].empty())
	  {
	    transform(y[0].begin(),y[0].end(),y[0].begin(), ::tolower);
	    y[0][0]=toupper(y[0][0]);
	    cout<<y[0]<<endl;
	  }
	  else if(!y[0].empty() && !y[1].empty() && y[2].empty())
	  {
	    transform(y[0].begin(),y[0].end(),y[0].begin(), ::tolower);
	    transform(y[1].begin(),y[1].end(),y[1].begin(), ::tolower);
	    y[0][0]=toupper(y[0][0]);
	    y[1][0]=toupper(y[1][0]);
	    cout<<y[0][0]<<"."<<" "<<y[1]<<endl;
	  }
	  else
	  {
	    transform(y[0].begin(),y[0].end(),y[0].begin(), ::tolower);
	    transform(y[1].begin(),y[1].end(),y[1].begin(), ::tolower);
	    transform(y[2].begin(),y[2].end(),y[2].begin(), ::tolower);
	    y[0][0]=toupper(y[0][0]);
	    y[1][0]=toupper(y[1][0]);
	    y[2][0]=toupper(y[2][0]);
	    cout<<y[0][0]<<"."<<" "<<y[1][0]<<"."<<" "<<y[2]<<endl;
	  }
	}
	
	return 0;
}
