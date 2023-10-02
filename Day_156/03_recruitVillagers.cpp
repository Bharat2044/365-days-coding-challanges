// Question Link: https://www.codechef.com/problems/VILLINE


#include <iostream>
using namespace std;

int main() {
	// your code goes here
	int n;
	cin>>n;
	
	int m,c;
	cin>>m>>c;
	
	int u=0;
	int k=0;
	
	for(int i=0;i<n;i++)
	{
	    int x,y,p;
	    cin>>x>>y>>p;
	    
	    if(y>(m*x)+c)
	    {
	        u=u+p;
	    }
	    else
	    {
	        k=k+p;
	    }
	}
	
	if(u>=k)
	{
	    cout<<u<<endl;
	}
	else
	{
	    cout<<k<<endl;
	}
	
	return 0;
}
