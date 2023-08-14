// Question Link: https://www.codechef.com/problems/ALEXNUMB


#include <iostream>
#include<algorithm>
#define l long long int
using namespace std;

int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--){
	   l n;
	   cin>>n;
	   l a[n];
	   
	    for(l i=0;i<n;i++)
	        cin>>a[i];
	   
	     l ans=((n*n)-n)/2;
	      cout<<ans<<endl;
	    
	}
	
	return 0;
}
