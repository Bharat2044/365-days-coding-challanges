// Question Link: https://www.codechef.com/problems/SLOWSOLN


#include <iostream>
using namespace std;

int main() {
    int t;
    cin >> t;

    for (int k = 0; k < t; k++) {
        int x, a, b;
        cin >> x >> a >> b;

        int d = b / a;
        int e = b % a;

        if (d < x)
            cout << e * e + d * a * a << endl;
        else
            cout << x * a * a << endl;
    }

    return 0;
}
