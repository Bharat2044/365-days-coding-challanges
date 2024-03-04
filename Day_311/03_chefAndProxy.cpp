// Question Link: https://www.codechef.com/problems/PROXYC


#include <bits/stdc++.h>
using namespace std;

int main() {
    // your code goes here
    int t;
    cin >> t;
    
    while (t--) {
        double target = 0, d, real = 0, proxy = 0;
        string s;
        
        cin >> d >> s;
        
        for (auto & i: s) {
            if (i == 'P') 
                real++;
        }
        
        for (int i = 0; i < d - 4; i++) {
            if ((s[i] == 'P' || s[i + 1] == 'P') && s[i + 2] == 'A' && (s[i + 3] == 'P' || s[i + 4] == 'P')) {
                proxy++;
            }
        }
        
        target = ceil(d * .75);
        if (real >= target) 
            cout << 0 << endl;
        else if (real + proxy >= target) 
            cout << target - real << endl;
        else 
            cout << -1 << endl;
    }
    
    return 0;
}
