// Question Link: https://codechef.com/problems/XORNEY


#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    while (t--) {
        long long int a, b, odd = 0;
        cin >> a >> b;

        if (a % 2 == 0 && b % 2 == 0) {
            odd = (b - a) / 2;
        }
        else if (a % 2 != 0 && b % 2 != 0) {
            odd = (b - a) / 2 + 1;
        }
        else {
            odd = (b - a + 1) / 2;
        }


        if (odd % 2 == 0) {
            cout << "Even\n";
        }
        else {
            cout << "Odd\n";
        }
    }
    
    return 0;
}
