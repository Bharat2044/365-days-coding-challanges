// Question Link: https://www.codechef.com/problems/TABLET


#include <iostream>
using namespace std;

int main() {
    // your code goes here
    int t;
    cin >> t;
    
    while (t--) {
        int n, b;
        int area = 0;
        
        cin >> n >> b;
        int flag = 0;
        
        for (int i = 1; i <= n; i++) {
            int w, h, p;
            cin >> w >> h >> p;
            
            if (p <= b) {
                if (area < w * h) {
                    area = w * h;
                    flag = 1;
                }
            }
        }

        if (flag == 1) {
            cout << area << endl;
        }
        else {
            cout << "no tablet" << endl;
        }
    }
    
    return 0;
}
