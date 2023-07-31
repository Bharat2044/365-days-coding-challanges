// Question Link: https://www.codechef.com/problems/DISABLEDKING


#include <iostream>
using namespace std;

int main() {
    int t;
    cin >> t;
    
    while (t--) {
        int n;
        cin >> n;
        
        if (n%2 == 1)
            cout<<n-1;
        else 
            cout << n;
        cout << endl;
    }
    
	return 0;
}
