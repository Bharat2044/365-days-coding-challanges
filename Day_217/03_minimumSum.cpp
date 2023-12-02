// Question Link: https://www.codechef.com/problems/MINSM


#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int t;
    cin>>t;
    
    while(t--){
        long long  n;
        cin>>n;
        
        long long a[n];
        for (long long i=0;i<n;i++)
            cin>>a[i];
  
        sort(a,a+n);
        long long g=a[0];
        
        for (long long i=1;i<n;i++)
            g = __gcd(g, a[i]); 
            
        cout<<g*n<<endl;
    }
    
	return 0;
}
