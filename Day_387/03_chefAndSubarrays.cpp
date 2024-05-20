// Question Link: https://www.codechef.com/problems/CHEFARRP


#include <iostream>
using namespace std;

int main() {
    int t;
    cin >> t;
    
    while (t--) {
        int num, cnt = 0;
        cin >> num;
        
        int arr[num];
 
        for (int i = 0; i < num; i++) {
            cin >> arr[i];
        }

        for (int i = 0; i < num; i++) {
            int sum = 0, pro = 1;
 
            for (int j = i; j < num; j++) {
                sum += arr[j];
                pro *= arr[j];
 
                if (sum == pro)
                    cnt++;
            }
        }
 
        cout << cnt << endl;
    }
 
    return 0;
}
