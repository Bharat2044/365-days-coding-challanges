// Question Link: https://www.codechef.com/problems/LIFTME


#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int T;
    cin >> T;

    for (int t = 0; t < T; ++t) {
        int N, Q;
        cin >> N >> Q;

        long long floor = 0;
        int current = 0;

        for (int i = 0; i < Q; ++i) {
            int s, d;
            cin >> s >> d;

            floor += abs(current - s) + abs(d - s);
            current = d;
        }

        cout << floor << endl;
    }

    return 0;
}
