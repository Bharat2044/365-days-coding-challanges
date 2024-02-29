// Question Link: https://www.codechef.com/problems/SINS


#include <iostream>
#include<algorithm>
using namespace std;

int main() {
	// your code goes here
	int T;
	cin>>T;
	
	while(T--){
	    int x,y;
	    cin>>x>>y;
	    
	    int gd=__gcd(x,y);
	    cout<<2*gd<<endl;
	}
	
	return 0;
}
