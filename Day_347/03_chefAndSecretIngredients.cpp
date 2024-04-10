// Question Link: https://www.codechef.com/problems/CHEFING


#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while (t--) {
        int n, ans = 0;
        cin >> n;

        string str;

        unordered_set < int > st; // to remove duplicates from string

        int freq[26] = {
            0
        }; // to keep track of freq of char

        for (int i = 0; i < n; i++) {
            cin >> str; // input string

            for (int i = 0; i < str.length(); i++) { // insert the char values in set 
                st.insert(str[i] - 'a');
            }
            for (auto i: st) {
                freq[i]++; // increment freq of every element present in this string
            }

            st.clear(); // empty set of next string

        }

        // every element with freq = n is present in all strings

        for (int i = 0; i < 26; i++) {
            if (freq[i] == n) ans++;
        }

        cout << ans << endl; // output

    }

    return 0;
}
