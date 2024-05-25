// Question Link: https://www.codechef.com/problems/BLNDOR


#include <iostream>
#include <algorithm>
using namespace std;

string can_be_eighth_power(int N, int arr[]) {
    sort(arr, arr + N);
    
    int count_2 = count(arr, arr + N, 2);
    int count_1 = count(arr, arr + N, 1);

    if (count_1 == N || count_2 % 8 == 0)
        return "Yes";
    else
        return "No";
}

int main() {
    int T;
    cin >> T;

    while (T--) {
        int N;
        cin >> N;
        int arr[N];

        for (int i = 0; i < N; ++i) {
            cin >> arr[i];
        }

        cout << can_be_eighth_power(N, arr) << endl;
    }

    return 0;
}
