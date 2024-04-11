// QUestion Link: https://www.codechef.com/problems/APPROX


#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    
    while (t--) {
        int n;
        cin >> n;
        
        if (n > 0)
            cout << "3.";
        else
            cout << "3";
    
        int x = 103993;
        int y = 33102;
        x %= y;
    
        for (int i = 0; i < n; i++) {
            x *= 10;
            cout << x / y;
            x %= y;
        }
    
        cout << endl;
    }
    
    return 0;
}
