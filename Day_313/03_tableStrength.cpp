// Question Link: https://www.codechef.com/problems/STRONGTABLE


#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin>>t;
    
    while(t--){
        int n;
        cin>>n;
        
        int a[n];
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        
        sort(a,a+n);
        int maxi=INT_MIN;
        
        for(int i=0;i<n;i++){
            int w=a[i]*(n-i);
            maxi=max(w,maxi);
        }
        
        cout<<maxi<<endl;
    }
        
    return 0;
}
