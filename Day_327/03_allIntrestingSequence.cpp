// Question Link: https://www.codechef.com/problems/INTSEQ


#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    
    while (t--) {
        int n, i = 2, count = 0;
        cin >> n;
        
        while (n % i == 0) {
            count++;
            i *= 2;
        }
        
        cout << count << endl;
    }
    
    return 0;
}
