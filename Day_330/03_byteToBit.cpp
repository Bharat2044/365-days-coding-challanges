// Question Link: https://www.codechef.com/problems/BITOBYT


#include <iostream>
#include<cmath>
using namespace std;

int main() {
    int t;
    cin >> t;
    
    while (t--) {
        int n;
        cin >> n;
        
        n--;
        
        long long c = n / 26;
        int rem = n % 26;
        c = pow(2, c);

        if (rem < 2)
            cout << c << " 0 0" << endl;
        else if (rem < 10)
            cout << "0 " << c << " 0" << endl;
        else
            cout << "0 0 " << c << endl;
    }
    
    return 0;
}
