// Question Link: https://www.codechef.com/problems/AMSGAME1


#include <iostream>
#include <algorithm>
 
using namespace std;
 
int main()
{
    int t;
    cin>>t;
    
    while(t--){
        int n;
        cin>>n;
        
        int a[n];
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        
        int x=a[0];
        for(int i=1;i<n;i++){
            x = __gcd(x, a[i]);
        }
        cout << x << endl;
    }
    
    return 0;
}
