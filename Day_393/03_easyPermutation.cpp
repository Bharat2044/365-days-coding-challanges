// Question Link: https://www.codechef.com/problems/EASYPERM


#include <iostream>
using namespace std;

int main() {
    // your code goes here
    int t;
    cin >> t;
    
    while (t--) {
        int n;
        cin >> n;
    
        for (int i = n; i > 0; i--) {
            cout << i << " ";
        }
    }
    
    return 0;
}
