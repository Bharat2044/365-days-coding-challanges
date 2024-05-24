// Question Link: https://www.codechef.com/problems/PRIME1


#include <bits/stdc++.h>
using namespace std;

bool primeGen(int n) {
    for (int i = 2; i <= sqrt(n); i++) {
        if (n % i == 0) {
            return false;
        }
    }

    return true;
}


int main() {
    int t;
    cin >> t;
    
    while (t--) {
        int a, b;
        cin >> a >> b;
    
        for (int i = a; i <= b; i++) {
            if (i == 1) 
                continue;
    
            if (primeGen(i)) {
                cout << i << endl;
            }
        }
    }
    
    return 0;
}
