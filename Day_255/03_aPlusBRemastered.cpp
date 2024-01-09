// Question Link: https://www.codechef.com/problems/APLUSB


#include <bits/stdc++.h>
using namespace std;

void solve() {    
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) cin >> b[i];
    
    sort(a.begin(), a.end());
    sort(b.begin(),b.end(), greater<int>());
    
    for (int i = 0; i < n; i++) {
        if (a[i]+b[i] != a[0]+b[0]) {
            cout << -1 << endl;
            return;
        }
    }
    
    for (int i = 0; i < n; i++) cout << a[i] << " "; cout << endl;
    for (int i = 0; i < n; i++) cout << b[i] << " "; cout << endl;
}

int main() {
    int t ;
    cin >> t;
    for (int i = 0; i < t; i++) {
        solve();
    }
}
