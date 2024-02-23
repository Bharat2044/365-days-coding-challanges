// Question Link: https://www.codechef.com/problems/FIZZBUZZ2304


#include <iostream>
using namespace std;

int main() {
    int t;
    cin>>t;
    
    while(t--) {
        int n,k;
        cin>>n>>k;
        
        int a[n];
        for(int i=0;i<n;i++)
            cin>>a[i];
        
        int i=0,j=k;
        int cnt=0;
        
        while(j<=n) {
            int f=0;
        
            for(int k=i;k<j;k++) {   
                if(a[k]%2!=0) {
                    f=1;
                    break;
                }
            }
            
            i++;
            j++;
            
            if(f==1)
                cnt++;
        }
        
        cout<<cnt<<"\n";
    }
    
	return 0;
}
