// Question Link: https://www.codechef.com/problems/SUPINC


#include <bits/stdc++.h>
using namespace std;

int main() {
    long long T;
    cin >> T;

    while (T--) {
        long long N, K, X, superArray = 1, count = 2;
        string str = "No";
        cin >> N >> K >> X;
        
        while (count < K) {
            superArray = superArray + superArray + 1;

            if (superArray >= X)
                break;
            count++;
        }

        if (K == 1 || superArray < X)
            str = "Yes";

        cout << str << endl;
    }
    
    return 0;
}
