// Question Link: https://www.codechef.com/problems/COUNTP


#include<bits/stdc++.h>
using namespace std;

int main() {

    int T, N, count;
    cin >> T;

    for (int i = 0; i < T; i++) {

        count = 0; // stores the no. of odd elements in complete array

        cin >> N;
        int arr[N];

        for (int j = 0; j < N; j++) { // input the elements into array
            cin >> arr[j];
        }

        for (int j = 0; j < N; j++) {
            if (arr[j] % 2 != 0)
                count++;
        }

        if (count % 2 != 0 || count == 0)
            cout << "NO" << endl;
        else
            cout << "YES" << endl;
    }

    return 0;
}
