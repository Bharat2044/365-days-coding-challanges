// Question Link: https://www.codechef.com/problems/SLAB


#include <bits/stdc++.h>

#define ll long long
using namespace std;

void solve() {
    ll n;
    cin >> n;
    
    ll temp = n;
    ll sum = 0;
    
    for (int i = 0; i <= 25; i += 5) {
        if (n > 250000)
            sum += (i * (250000) / 100);
        else {
            sum += ((i * n) / 100);
            n = 0;
            break;
        }
        
        n -= 250000;
    }

    if (n > 0)
        sum += ((30 * n) / 100);

    cout << (temp - sum);
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        solve();
        cout << endl;
    }
    
    return 0;
}
