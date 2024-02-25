// Question Link: https://www.codechef.com/problems/MISSSUMS


#include<bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        long long int r = 1;

        for (int i = 1; i <= n; i++) {
            cout << r << " ";
            r = r + 2;
        }

        cout << endl;
    }

    return 0;
}
