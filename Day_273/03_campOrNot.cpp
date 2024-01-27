// Question Link: https://www.codechef.com/problems/CAMPON


#include <iostream>
using namespace std;

int main() {
	// your code goes here
	int t;
	cin>>t;
	
	while(t--)
	{
	    long long D;
	    cin>>D;
	    long long d[D],p[D];
	    
	    for(int i = 0; i<D; i++)
	    {
	        cin>>d[i]>>p[i];
	    }
	    
	    long long q;
	    cin>>q;
	    long long dead,req;
	    
	    for(int i = 0; i<q; i++)
	    {
	        cin>>dead>>req;
	        long long sum = 0;
	        
	        for(int j =0; j<D; j++)
	        {
	            if(d[j]<=dead)
	            {
	                sum += p[j];
	            }
	        }
	        
	        if(sum>= req)
	        {
	            cout<<"Go Camp"<<endl;
	        }
	        else
	        {
	            cout<<"Go Sleep"<<endl;
	        }
	    }
	}
	
	return 0;
}
