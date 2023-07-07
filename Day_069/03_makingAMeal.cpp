// Question Link: https://www.codechef.com/problems/CFMM


#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;
	while (t--) {
	    int n;
	    cin >> n;
	    unordered_map<char, int> um;
	    for (int i = 0; i < n; ++i) {
	        string s;
	        cin >> s;
	        for (char j: s) {
	            um[j]++;
	        }
	    }
	    
	    cout << min({um['c'] / 2, um['o'], um['d'], um['e'] / 2, um['h'], um['f']}) << endl;
	}
	
	return 0;
}
