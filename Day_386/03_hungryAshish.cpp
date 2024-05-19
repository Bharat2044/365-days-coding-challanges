// Question Link: https://www.codechef.com/problems/PIZZA_BURGER


#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    
    while (t--) {
        int x, y, z;
        cin >> x >> y >> z;
        
        if (x >= y) {
            cout << "PIZZA" << endl;
        }
        else if (x < y && x >= z) {
            cout << "BURGER" << endl;
        }
        else {
            cout << "NOTHING" << endl;
        }
    }

    return 0;
}
