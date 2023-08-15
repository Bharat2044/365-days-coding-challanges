// Question Link: https://www.codechef.com/problems/GARDENSQ


#include <iostream>
#include <vector>
using namespace std;

void solve() {
    int N, M;
    cin >> N >> M;
    
    vector<vector<char>> matrix(N, vector<char>(M));
    for (int i = 0; i < N; ++i) {
        string l;
        cin >> l;
        
        for (int j = 0; j < M; ++j) {
            matrix[i][j] = l[j];
        }
    }

    int ans = 0;
    
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            char same = matrix[i][j];
            int delta = 1;
            
            while ((i + delta) < N && (j + delta) < M) {
                if (matrix[i + delta][j] == same && matrix[i][j + delta] == same && matrix[i + delta][j + delta] == same) {
                    ans++;
                }
                
                delta++;
            }
        }
    }
    
    cout << ans << endl;
}

int main() {
    int t;
    cin >> t;
    
    while (t--) {
        solve();
    }
    
    return 0;
}
