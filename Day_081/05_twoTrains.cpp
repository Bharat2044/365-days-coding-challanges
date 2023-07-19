// Question Link: https://www.codechef.com/problems/TWOTRAINS


#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	int t;
	cin >> t;
	
	while(t--) {
	    int n, sum=0, max1 = INT_MIN;
	    cin >> n;
	    vector<int> p(n-1);
	    
	    for(int i=0; i<n-1; i++){
	        cin >> p[i];
	        sum += p[i];
	        max1 = max(max1, p[i]); 
	    }
	    
	    cout << sum+max1 << endl;
	}
	
	return 0;
}
