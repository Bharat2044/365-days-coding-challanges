// Question Link: https://www.codechef.com/problems/HOWMANYMAX



#include <iostream>
using namespace std;

int main() {
	int t;
	cin >> t;
	
	while (t--) {
	    int n;
	    string s;
	    cin >> n >> s;
	    
	    int count = 1;
	    
	    for (int i = 0; i < n - 1; ++i) {
	        if (s[i] == '1' && s[i + 1] == '0') 
	            count++;
	    }
	    
	    cout << count << endl;
	}
	
	return 0;
}
