// Question Link: https://www.codechef.com/problems/MAX1XOR


#include <iostream>

#include<bits/stdc++.h>

#define ll long long
using namespace std;

int main() {
    // your code goes herei
    int t;
    cin >> t;

    while (t--) {
        ll n;
        cin >> n;

        string s;
        cin >> s;

        int c1 = 0, c2 = 0;
        int i;
        string x, x1;

        x.push_back('0');
        x1.push_back('1');

        for (i = 0; i < (n - 1); i++) {
            if (s[i] == '0') {
                if (x1[i] == '1')
                    x1.push_back('1');
                else
                    x1.push_back('0');

                if (x[i] == '1')
                    x.push_back('1');
                else
                    x.push_back('0');
            }
            else if (s[i] == '1') {
                if (x1[i] == '0')
                    x1.push_back('1');
                else
                    x1.push_back('0');

                if (x[i] == '0')
                    x.push_back('1');
                else
                    x.push_back('0');
            }
        }

        for (i = 0; i < n; i++) {
            if (x[i] == '1')
                c1++;

            if (x1[i] == '1')
                c2++;
        }

        cout << max(c1, c2) << endl;
    }

    return 0;
}
