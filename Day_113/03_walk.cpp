// Question Link: https://www.codechef.com/problems/WALK


#include <iostream>
using namespace std;

int main() {
	int t, a, n;
	cin>>t;
  
	while(t--)
	{
	    cin >> n;
	    int m = 0;
    
	    for(int i=0; i<n; i++)
	    {
	        cin >> a;
	        m = max(m, a+i);
	    }
    
	    cout << m << endl;
	}
  
	return 0;
}
