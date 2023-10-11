// Question Link: https://www.codechef.com/problems/ICL1801


#include <iostream>
#include<bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	int t;
	cin>>t;
	
	while(t--)
	{
	    int n,m;
	    cin>>n>>m;
	    
	    vector<int>v ;
	    int i,sum1=0,sum2=0;
	    
	    for(i=0;i<(n*m);i++)
	    {
	        int temp;
	        cin>>temp;
	        v.push_back(temp);
	    }
	
	    sort(v.begin() , v.end(), greater<int>());
	
	    for(i=0;i<(n*m);i++)
	    {
	        if(i%2==0)
	        {
	            sum1+=v[i];
	        }
	        else
	        {
	            sum2+=v[i];
	        }
	    }
	    
	    if(sum1>sum2)
	    {
	        cout<<"Cyborg\n";
	    }
	    else if(sum2>sum1)
	    {
	        cout<<"Geno\n";
	    }
	    else
	    {
	        cout<<"Draw\n";
	    }
	}
	
	return 0;
}
