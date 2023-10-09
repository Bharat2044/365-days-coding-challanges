// Question Link: https://www.codechef.com/problems/BULLBEAR


#include <iostream>
using namespace std;

int main() {
	int t, x, y;
	cin >> t;
	
	while (t--) {
	    cin >> x >> y;
	    cout << (x > y ? "LOSS\n" : (x == y ? "NEUTRAL\n" : "PROFIT\n"));
	}
	
	return 0;
}
