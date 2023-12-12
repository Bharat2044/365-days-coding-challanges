// Question Link: https://www.codechef.com/problems/HLEQN


#include <iostream>
#include<algorithm>
#include<math.h>
using namespace std;

int main() {
	// your code goes here
	long long t;
	cin>>t;
	
	while(t--)
	{
	    long long x;
	    cin>>x;
	    
	    if(x<5)
	    {
	        cout<<"NO"<<endl;
	    }
	    else
	    {
	        int flag = 0;
	        
	        for(int a = 1; a<sqrt(x); a++)
	        {
    	        if((x-(2*a)) % (a+2) == 0)
    	        {
    	            flag = 1;
    	            break;
    	        }
	        }
	        
    	    if(flag == 0)
    	    {
    	        cout<<"NO"<<endl;
    	    }
    	    else
    	    {
    	        cout<<"YES"<<endl;
    	    }
	    }
	}
	
	return 0;
}
	 
