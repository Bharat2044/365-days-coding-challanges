// Question Link: https://www.codechef.com/problems/LOSTWKND


#include<bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    
    while (t--) {
        int p, ele, sum = 0;
    
        for (int i = 0; i < 5; i++) {
            cin >> ele;
            sum += ele;
        }
    
        cin >> p;
        sum *= p;
    
        if (sum <= 120) {
            cout << "No" << endl;
        }
        else {
            cout << "Yes" << endl;
        }
    }
    
    return 0;
}
