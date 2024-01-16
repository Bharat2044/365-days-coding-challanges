// Question Link: https://www.codechef.com/problems/DEVUGRAP


#include <iostream>
using namespace std;

int main() {
    int t;
    cin>>t;
    
    while(t--){
        long long n,k;
        cin>>n>>k;
        
        long long g[n],c=0;
        
        for(long long i=0;i<n;i++){
            cin>>g[i];
            if(g[i]>=k)
            {
                if(g[i]%k<=k/2)
                    c+=g[i]%k;
                else
                    c+=k-g[i]%k;
            }
            else
                c+=k-g[i];
        }
        cout<<c<<endl;
    }
    
	return 0;
}
