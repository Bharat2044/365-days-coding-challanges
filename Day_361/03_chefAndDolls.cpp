// Question Link: https://www.codechef.com/problems/MISSP


#include <iostream>
using namespace std;

int main() {
    int test;
    cin >> test;
    int n = 0;

    while (test--) {
        cin >> n;
        int d[n];

        for (int i = 0; i < n; i++)
            cin >> d[i];


        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (d[i] == d[j])
                    d[i] = d[j] = -1;
            }
        }

        for (int i = 0; i < n; i++) {
            if (d[i] != -1)
                cout << d[i] << endl;
        }

    }
    
    return 0;
}
