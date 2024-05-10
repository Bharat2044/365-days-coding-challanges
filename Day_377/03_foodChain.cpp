// Question Link: https://www.codechef.com/problems/FODCHAIN


#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int t;
    cin >> t;
    
    while (t--) {
        unsigned long e, k;
        cin >> e >> k;

        int ans = 0;

        do {
            ans++; //1
            e = floor(e / (float) k); //
        } while (e > 0);
        
        cout << ans << endl;
    }

    return 0;
}
