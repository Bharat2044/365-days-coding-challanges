// Question Link: https://www.codechef.com/problems/CHBLLNS


#include <iostream>
using namespace std;

int main() {
    // your code goes here
    int t;
    cin >> t;
    
    while (t--) {
        int r, g, b, k;
        cin >> r >> g >> b >> k;
    
        int r_b = 0, g_b = 0, b_b = 0;

        r_b = (r >= k) ? k - 1 : r;
        g_b = (g >= k) ? k - 1 : g;
        b_b = (b >= k) ? k - 1 : b;

        cout << (long long int) r_b + g_b + b_b + 1 << endl;
    }
    
    return 0;
}
