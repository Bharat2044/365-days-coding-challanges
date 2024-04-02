// Question Link: https://www.codechef.com/problems/CHEFLR


#include <bits/stdc++.h>
using namespace std;

#define ll long long int
const int mod = 1e9 + 7;

int main() {
    int t;
    cin >> t;
    
    while (t--) {
        ll ans = 1;
        string s;
        cin >> s;

        for (int i = 0; i < s.length(); i++) {
            if ((i + 1) & 1) {
                if (s[i] == 'l') ans = (ans * 2);
                else ans = (ans * 2) + 2;
            }
            else {
                if (s[i] == 'l') ans = (ans * 2) - 1;
                else ans = (ans * 2) + 1;
            }
            ans %= mod;
        }
        
        cout << ans << endl;
    }
    
    return 0;
}
