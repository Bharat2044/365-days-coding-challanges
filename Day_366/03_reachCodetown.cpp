// Question Link: https://www.codechef.com/problems/CODETOWN


#include <bits/stdc++.h>
using namespace std;

bool isVowel(char ch) {
    ch = toupper(ch);
    return (ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U');
}

bool canReachCODETOWN(const string & town) {
    string convertedTown;
    for (char ch: town) {
        if (isVowel(ch))
            convertedTown += 'V'; // V for Vowel
        else
            convertedTown += 'C'; // C for Consonant
    }

    return convertedTown == "CVCVCVCC";
}

int main() {
    int T;
    cin >> T;

    while (T--) {
        string town;
        cin >> town;

        if (canReachCODETOWN(town)) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }

    return 0;
}
