// Question Link: https://www.codechef.com/problems/MD_RIEV


#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	int t;
	cin >> t;
	
	while(t--) {
	    int n;
	    cin >> n;
	    
	    if(n <= 4) {
	        cout << 0 << " " << n << endl;
	    }
	    else {
	        cout << 1 << " " <<  n-1 << endl;
	    }
	}
	
	return 0;
}
