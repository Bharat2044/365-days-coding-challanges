// Question Link: https://www.codechef.com/problems/NEWPIECE


#include <iostream>
using namespace std;  

int main(){
    int t;
    cin >> t;
    
    while (t--) {
        int a, b, p, q;
        cin >> a >> b >> p >> q;
        
        int x = a + b;
        int y = p + q;
        
        if (x%2 != y%2) 
            cout<<"1\n";     
        else if (a==p && b==q) 
             cout<<"0\n";
        else 
            cout<<"2\n";
    }
    
    return 0;

}
