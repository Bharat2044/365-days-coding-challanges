// Question Link: https://www.codechef.com/problems/MKEQ


#include<bits/stdc++.h>
using namespace std;
#define ll long long

void solve() {
    int n;
    cin >> n;
    
    vector < ll > v(n);
    
    for (auto & x: v) 
        cin >> x;

    ll mini = * min_element(v.begin(), v.end());
    
    cout << (mini == v[0] && mini == v[n - 1] ? "YES" : "NO") << endl;
}

int main() {
    int tc;
    cin >> tc;

    while (tc--) 
        solve();

    return 0;
}
