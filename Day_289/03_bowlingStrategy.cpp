// Question Link: https://www.codechef.com/problems/BOWLERS


#include <bits/stdc++.h>

using namespace std;
#define ll long long

int main() {
    ll t;
    cin >> t;
    while (t--) {
        ll n, k, l;
        cin >> n >> k >> l;
        if (k * l < n || (k == 1 && n > 1)) cout << -1 << endl; // corner cases
        else {

            int c = 0;
            bool flag = true;
            for (int i = 0; i < l; i++) {
                for (int j = 1; j <= k; j++) {
                    if (c >= n) {
                        flag = false;
                        break;
                    }
                    cout << j << " ";
                    c++;
                }

                if (flag == false) break;
            }
            cout << endl;
        }
    }

    return 0;
}
