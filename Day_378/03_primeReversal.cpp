// Question Link: https://www.codechef.com/problems/PRIMEREVERSE


#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    long long t;
    cin >> t;
    
    for (long long i = 0; i < t; ++i) {
        long long k;
        cin >> k;
    
        string s, d;
        cin >> s >> d;
    
        sort(s.begin(), s.end());
        sort(d.begin(), d.end());
    
        if (s == d) {
            cout << "yes" << endl;
        } else {
            cout << "no" << endl;
        }
    }
    
    return 0;
}
