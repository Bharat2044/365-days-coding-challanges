// Question Link: https://www.codechef.com/problems/LOSTMAX


#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    
    cin.ignore();

    while (t--) {
        string c;
        getline(cin, c);

        // Used stringstream for spliting the string
        stringstream cs(c);
        long long d;
        vector < long long > a;

        while (cs >> d) {
            a.push_back(d);
        }

        if (a.size() != 1) {
            a.erase(find(a.begin(), a.end(), a.size() - 1));
            sort(a.begin(), a.end());
        }

        cout << a[a.size() - 1] << endl;
    }
    
    return 0;
}
