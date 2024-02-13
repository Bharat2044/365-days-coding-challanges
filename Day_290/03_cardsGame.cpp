// Question Link: https://www.codechef.com/problems/ICL1701


#include<bits/stdc++.h>
using namespace std;

int main() {
    int a, b;
    cin >> a >> b;
    int arr[a];
    
    for (int r = 0; r < a; r++) {
        cin >> arr[r];
    }
    
    int z = 0;
    vector < int > v;
    
    for (int r = 0; r < a - 1; r++) {
        if (arr[r] < 0) {
            arr[r] = arr[r] * (-1);
            arr[r + 1] = arr[r + 1] * (-1);
            z++;
            v.push_back(r + 1);
        }
    }
    
    if (arr[a - 1] < 0) {
        z++;
        v.push_back(a);
    }
    
    cout << z << endl;
    for (auto i: v) {
        cout << i << " ";
    }
    
    return 0;
}
