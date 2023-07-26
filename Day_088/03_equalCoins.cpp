// Question Link: https://www.codechef.com/problems/EQUALCOIN


#include <iostream>
using namespace std;

int main() {
	// your code goes here
	int t;
	cin >> t;
	
	while(t--) {
	    int x, y;
	    cin >> x >> y;
	    
	    if((x+2*y)%2 || (x<2 && y%2))
	        cout << "NO\n";
	    else 
	        cout << "YES\n";
	}
	
	return 0;
}
