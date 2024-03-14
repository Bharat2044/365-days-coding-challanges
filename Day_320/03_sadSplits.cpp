// Question Link: https://www.codechef.com/problems/SPLITPAIR


#include <bits/stdc++.h>
using namespace std;

int main() {
    // your code goes here
    int t;
    cin >> t;
    
    while (t--) {
        long long n, e = 0;

        cin >> n;
        long long n1 = n, o = 0;

        while (n > 0) {
            if (n % 2 == 0)
                e++;
            else
                o++;
                
            n = n / 10;
        }

        if (n1 % 2 == 0 && e > 1)
            cout << "yes\n";
        else if (n1 % 2 != 0 && o > 1)
            cout << "yes\n";
        else
            cout << "no\n";
    }
    
    return 0;
}
