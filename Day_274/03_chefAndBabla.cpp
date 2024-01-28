// Question Link: https://www.codechef.com/problems/BAB_I


#include<bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin>>t;
    
    while(t--){
        int n;
        cin>>n;
        
        int arr[n];
        bool A=0;
        
        for(int i=0;i<n;i++){
            int a;
            cin>>a;
            
            arr[i]=abs(a);
            if(arr[i]==0){
                A=1;
            }
        }
        
        sort(arr, arr+n);
        if(A==1){
            cout<<-1<<endl;
        }
        else{
            cout<<arr[0]- 1<<endl;
        }
    }
    
    return 0;
}
