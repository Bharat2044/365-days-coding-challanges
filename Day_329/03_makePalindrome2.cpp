// Question Link: https://www.codechef.com/problems/MAKEPAL2


#include<bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    
    while (t--) {
        int n;
        cin >> n;
        
        string s;
        cin >> s;
        
        int c = 0, d = 0;
        
        for (int i = 0; i < n; i++) { //logic is simple.....
            if (s[i] == '1')
                c++; //count o's and 1's;
            else
                d++;
        }
        if (c >= d) //print greatr count
            for (int i = 0; i < c; i++)
                cout << 1;
        else
            for (int i = 0; i < d; i++)
                cout << 0;
                
        cout << endl;
    }
    
    return 0;
}
