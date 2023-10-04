// Question Link: https://www.codechef.com/problems/POPGATES


#include <iostream>
#include <string>
using namespace std;

int main() {
    long int t;
    cin >> t;
    while (t--) {
        long int n, k;
        cin >> n >> k;
        string s;
        for(int i=0;i<n;i++)
        {
            char bit;
            cin>>bit;
            s.push_back(bit);
        }

        for (int i = 0; i < k; i++) {
            if (s[n - 1] == 'H') {
                for (int j = 0; j < n; j++) {
                    if (s[j] == 'H') {
                        s[j] = 'T';
                    } else {
                        s[j] = 'H';
                    }
                }
            }
            n--; // Remove the rightmost coin
        }

        int count = 0;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == 'H') {
                count++;
            }
        }
        cout << count << endl;
    }

    return 0;
}
