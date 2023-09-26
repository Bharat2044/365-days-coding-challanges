// Question Link: https://www.codechef.com/problems/COMMUTE


#include <iostream>
using namespace std;

int main() {
	int t;
	cin >> t;
	
	while( t--)
	{
	    int n = 0;cin >>n;
	    int a[n][3];
	    
	    for(int i = 0; i < n; i++)
	        cin >> a[i][0] >> a[i][1]>> a[i][2];
	    
	    int tot = 0;
	    for(int i = 0; i < n; i++)
	    {
	        int xi = a[i][0];
	        int ii = a[i][1];
	        int fi = a[i][2];
	        //cout << xi <<" "<<ii<<" "<<fi<<" tot : "<<tot<<endl;
	        
	        if(tot < xi)
	            tot += (xi-tot) + ii;
	        else
	        {
	            if( (tot-xi)%fi == 0)
	                tot+=ii;
	            else
	                tot += (fi-((tot-xi)%fi)) + ii;
	        }
	           
	    }
	    
	    cout << tot << "\n";
	}
	
	return 0;
}
