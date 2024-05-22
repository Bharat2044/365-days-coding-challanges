// Question Link: https://www.codechef.com/problems/ENCMSG


#include <iostream>
using namespace std;

int main() {
    // your code goes here
    int t;
    cin >> t;
    
    while (t--) {
        int n;
        cin >> n;
        
        string s;
        cin >> s;
        
        for (int i = 0; i < n - 1; i += 2) {
            swap(s[i], s[i + 1]);
        }
        
        for (int i = 0; i < n; i++) {
            int d = s[i] - 'a';
            char c = 'z' - d;
            
            cout << c;
        }
        
        cout << endl;
    }
    
    return 0;
}
