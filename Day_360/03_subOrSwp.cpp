// Question Link: https://www.codechef.com/problems/ASM120


#include <iostream>
using namespace std;

int ace(int p, int q) {
    while (q) {
        int temp = q;
        q = p % q;
        p = temp;
    }
    return p;
}

int finalValue(int x, int y) {
    return ace(x, y);
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        int x, y;
        cin >> x >> y;
        cout << finalValue(x, y) << endl;
    }

    return 0;
}
