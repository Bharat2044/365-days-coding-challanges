// Question Link: https://www.codechef.com/problems/SHUFFLIN


#include <bits/stdc++.h>

typedef long long ll;
using namespace std;

int main() {
    ll n, t, odd, even, res;
    cin >> t;
    
    while (t--) {
        cin >> n;
        vector < ll > input(n);
        
        for (ll i = 0; i < n; ++i) 
            cin >> input[i];

        odd = 0;
        for (ll i = 0; i < n; ++i)
            if (input[i] % 2 != 0) 
                ++odd;
                
        even = n - odd;

        if (n % 2 == 0) 
            res = min(even, n / 2) + min(odd, n / 2);
        else 
            res = min(even, n / 2 + 1) + min(odd, n / 2);
    
        cout << res << endl;
    }
    
    return 0;
}
