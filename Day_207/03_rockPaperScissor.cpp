// Question Link: https://www.codechef.com/problems/PASCRO


#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        string A ;
        cin >> A ;
      
        string B ;
        cin>> B;

        int counter1 = 0, counter2 = 0;

        for (int i = 0; i < n; i++) {
            if ((A[i] == 'R' && B[i] == 'P') || (A[i] == 'S' && B[i] == 'R') || (A[i] == 'P' && B[i] == 'S')) {
                counter2 ++;
            }
            else if ((A[i] == 'R' && B[i] == 'S') || (A[i] == 'P' && B[i] == 'R') || (A[i] == 'S' && B[i] == 'P')) {
                counter1 ++;
            } 
            
        }

        int num = 0;
        if (counter2 >= counter1) {
            num = ((counter1 + counter2) / 2) + 1;
            cout << num - counter1 << endl;
        } 
        else 
            cout << 0 << endl;
        
    }

    return 0;
}
