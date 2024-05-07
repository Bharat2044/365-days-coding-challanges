// Question Link: https://www.codechef.com/problems/CNDLOVE


#include<iostream>
using namespace std;

int main() {
    int t, n;
    cin >> t;
    
    while (t--) {
        int sum = 0;
        cin >> n;
    
        int arr[n]; // will denote the number of candies in n packets

        for (int i = 0; i < n; i++) {
            cin >> arr[i];
            sum += arr[i];
        }

        if (sum & 1) {
            cout << "YES" << endl;
        }
        else {
            cout << "NO" << endl;
        }
    }
    
    return 0;
}
