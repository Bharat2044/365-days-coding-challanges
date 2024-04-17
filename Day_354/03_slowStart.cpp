// Question Link: https://www.codechef.com/problems/SLOWSTART


#include <iostream>
using namespace std;

int main() {

    int t;
    cin >> t;

    for (int i = 0; i < t; i++) {

        int x, h;
        cin >> x >> h;

        int k = 0;
        
        while (h > 0) {
            if (k < 5) {
                h = h - x / 2;
                k++;
            }
            else {
                h = h - x;
                k++;
            }
        }

        cout << k << endl;
    }

    return 0;
}
