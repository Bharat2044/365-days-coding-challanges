// Question Link: https://www.codechef.com/problems/SPOON


#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	int t;
	cin>>t;
	
	for(int i=0; i<t; i++)
	{
	    int r,c;
	    cin>>r>>c;
	    vector<char> v;
	    
	    for(int j=0; j<r; j++)
	    {
	        for(int k=0;k<c; k++)
	        {
	            char ch;
	            cin>>ch;
	            
	            v.push_back(tolower(ch));
	        }
	    }
	    int flag=0;
	    
	    for(int j=0; j<(r*c)-4; j++)
	    {
	        if(v[j]=='s' && v[j+1]=='p' && v[j+2]=='o' && v[j+3]=='o' && v[j+4]=='n')
	        {
	            flag=1;
	            cout<<"There is a spoon!"<<endl;
	            break;
	        }
	        else if(v[j]=='s' && v[c+j]=='p' && v[2*c + j]=='o' && v[3*c +j]=='o' && v[4*c +j]=='n')
	        {
	            flag=1;
	            cout<<"There is a spoon!"<<endl;
	            break;
	        }
	        else
	        {
	            continue;
	        }
	    }
	    
	    if(flag==0)
	    {
	        cout<<"There is indeed no spoon!"<<endl;
	    }
	}
	
	return 0;
}
