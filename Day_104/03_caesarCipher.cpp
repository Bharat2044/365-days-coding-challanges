// Question Link: https://www.codechef.com/problems/CAESAR


#include <iostream>
#include <string>

using namespace std;

string getROTKCipher(const string& S, const string& T, const string& U) {
    int N = S.length();
    int K = 0;
    
    // Find the value of K (number of positions shifted)
    for (int i = 0; i < N; i++) {
        int diff = (T[i] - S[i] + 26) % 26;  // +26 to handle negative differences
        if (K == 0)
            K = diff;
        else if (K != diff)
            return "";  // Invalid input, cannot determine a single value for K
    }
    
    // Shift each character of U by K positions to get the ROT-K cipher
    string cipher = U;
    for (char& c : cipher) {
        c = 'a' + (c - 'a' + K) % 26;  // Shift the character by K positions
    }
    
    return cipher;
}

int main() {
    int Q;
    cin >> Q;

    for (int q = 0; q < Q; q++) {
        int N;
        cin >> N;
        string S, T, U;
        cin >> S >> T >> U;
        
        string cipher = getROTKCipher(S, T, U);
        cout << cipher << endl;
    }

    return 0;
}
