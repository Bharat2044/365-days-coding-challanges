// Question Link: https://www.codechef.com/problems/ADADISH


#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n;
    cin >> n;
    int c[n];
    
    for (int i = 0; i < n; i++) 
        cin >> c[i];
    
    
    sort(c, c+n, greater<int>());
    int ans = 0, var = 0;
    
    for (int i = 0; i < n; i++) {
        if(var<ans)
            var += c[i];
        else 
            ans += c[i];
    }
    
    cout << max(var, ans) << std::endl;
}

int main() {
	int t;
	cin >> t;
	
	for (int i = 0; i < t; i++) 
	    solve();
	
	
	return 0;
}
