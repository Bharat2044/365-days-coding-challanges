// Question Link: https://www.codechef.com/problems/GAME_XI


#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int t;
    cin >> t;
    
    while (t--) {
        int n, m;
        cin >> n >> m;
       
        vector < int > batsmen(n), bowlers(m);
       
        for (int i = 0; i < n; i++)
            cin >> batsmen[i];
            
        for (int i = 0; i < m; i++)
            cin >> bowlers[i];

        sort(batsmen.begin(), batsmen.end(), greater < int > ());
        sort(bowlers.begin(), bowlers.end(), greater < int > ());

        long long total = 0;

        if (n < 4 || m < 4 || n + m < 11) {
            cout << -1 << endl;
            continue;
        }
        
        for (int i = 0; i < 4; i++)
            total += batsmen[i];
            
        for (int i = 0; i < 4; i++)
            total += bowlers[i];
            
        int i = 4, j = 4, count = 0;
        
        while (count < 3 && (i < n || j < m)) {
            if (i < n && j < m) {
                if (batsmen[i] > bowlers[j]) {
                    total += batsmen[i];
                    i++;
                }
                else {
                    total += bowlers[j];
                    j++;
                }
            }
            else if (i < n) {
                total += batsmen[i];
                i++;
            }
            else if (j < m) {
                total += bowlers[j];
                j++;
            }
            
            count++;
        }

        cout << total << endl;
    }
    
    return 0;
}
