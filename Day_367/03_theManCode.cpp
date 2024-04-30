// Question Link: https://www.codechef.com/problems/MANCODE


#include <bits/stdc++.h>
using namespace std;

void fun() {
    int n, m;
    cin >> n;
    
    if (n == 1)
        cout << "1  1";
    else {
        cout << n / 2 + (n % 2);
        if (n % 3 == 0)
            cout << " " << n / 3;
        else
            cout << " " << n / 3 + 1;
    }

    cout << endl;
}

int main() {
    // your code goes here
    int t;
    cin >> t;
    
    for (int i = 0; i < t; i++)
        fun();

    return 0;
}
