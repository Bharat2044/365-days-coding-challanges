// Question Link: https://www.codechef.com/problems/NAME1


#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    
    while (t--) {
        bool f = 1;
        string a, b;
        cin >> a >> b;
        
        a = a + b;
        int n;
        cin >> n;
        
        string c;
        
        for (int i = 0; i < n; i++) {
            string x;
            cin >> x;
            c += x;
        }

        unordered_map < char, int > m;
        for (int i = 0; i < a.length(); i++)
            m[a[i]]++;

        for (int i = 0; i < c.length(); i++) {
            m[c[i]]--;

            if (m[c[i]] < 0)
                f = 0;
        }

        if (f)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    
    return 0;
}
