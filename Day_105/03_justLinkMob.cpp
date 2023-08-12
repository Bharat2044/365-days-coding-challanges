// Question Link: https://www.codechef.com/problems/MOBKUN


#include <iostream>
using namespace std;

int main() {
	// your code goes here
	int n;
	cin>>n;
	
	for(int i=0;i<n;i++) {
	    int y1,m,k,d;
	    cin>>y1>>m>>k>>d;
	    
	    int elements=y1*(k-1);
	    int mobdays=y1*k+m;
	    int rem=d%mobdays;
	    
	    if(rem==0 || (rem-elements)>0) 
	        cout<<"YES"<<endl;
	    else 
	        cout<<"NO"<<endl;
	}
	
	return 0;
}
