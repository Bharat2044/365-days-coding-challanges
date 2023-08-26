// Question Link: https://www.codechef.com/problems/S02E10


#include <iostream>
#include <vector>
using namespace std;

int main() {
	int t, n, x, k;
	cin >> t;
	
	while (t--) {
	    cin >> n >> x >> k;
	    
	    vector <int> a(n), b(n);
	    
	    for (auto &i: a)
	        cin >> i;
	    for (auto &i: b)
	        cin >> i;
	        
	    for (int i = 0; i < n; ++i) {
	        if (abs(a[i] - b[i]) <= k) {
	            if (x == 0 || x > n)
	                break;
	            --x;
	        }
	    }
	    
	    if (x <= 0)
	        cout << "YES\n";
	    else
	        cout << "NO\n";
	}
	
	return 0;
}
