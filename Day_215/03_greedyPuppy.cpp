// Question Link: https://www.codechef.com/problems/GDOG


#include <iostream>
using namespace std;

int main() {
	int t;
	cin >> t;
	
	while( t--)
	{
	    int n = 0, k =0;
	    cin >>n >>k;
	    
	    int max =0;
	    int h=k;
	    
	    while(k>h/2)
	    {
	        if(n%k > max) 
	         max = n%k; 
	        k--;
	    }
	    
	    cout<<max<<endl;
	 
	}
	
	return 0;
}
