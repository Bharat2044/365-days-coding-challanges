// Question Link: https://www.codechef.com/problems/ALTTAB


#include <iostream>

#include <string>

#include <vector>
#include <unordered_map>

using namespace std;

int main() {
    // your code goes here

    int n;
    cin >> n;

    // 	string s[n];
    vector < string > s(n);

    for (int i = 0; i < n; i++) {
        cin >> s[i];
    }

    unordered_map < string, int > ump;
    string str = "";

    for (int it = s.size() - 1; it >= 0; it--) {
        string st = s[it];

        if (ump.find(st) != ump.end())
            continue;
        else {
            str += st[st.size() - 2];
            str += st[st.size() - 1];
            ump[st]++;
        }
    }

    cout << str;

    return 0;
}
