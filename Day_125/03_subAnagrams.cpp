// Question Link: https://www.codechef.com/problems/SUBANAGR


#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    string a;
    cin >> a;
    
    for (int i = 1; i < n; i++) {
        string b, s = "";
        cin >> b;
        
        for (int p = 0; p < a.size(); p++) {
            for (int q = 0; q < b.size(); q++) {
                if (a[p] == b[q]) {
                    s += b[q];
                    b.erase(b.begin() + q, b.begin() + q + 1);
                    break;
                }
            }
        }
        a = s;
    }
    
    sort(a.begin(), a.end());
    if (a.length() == 0)
        cout << "no such string" << endl;
    else
        cout << a << endl;
        
    return 0;
}
