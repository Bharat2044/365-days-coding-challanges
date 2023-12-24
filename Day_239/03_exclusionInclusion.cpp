// Link Link: https://www.codechef.com/problems/ONEFROMK


#include <iostream>
#include<algorithm>
using namespace std;

int main() {
    int t;
    cin>>t;
    
    while(t--){
       long long  int n;
        cin>>n;
        long long int a[n],sum=0,m=0;
        
        for(int i=0;i<n;i++){
            cin>>a[i];sum+=a[i];
        }
        
        cout<<sum<<" ";
        sort(a,a+n);m=sum;
        
        for(int i=0;i<n;i++){
            m=m-a[i];if(m>0){
            cout<<m<<" ";
            }
        }
        cout<<endl;
    }
    	
    return 0;
}
