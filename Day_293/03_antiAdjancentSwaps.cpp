// Question Link: https://www.codechef.com/problems/ANADSW


#include <bits/stdc++.h>
using namespace std;

int main() {
    int pt;
    cin>> pt;
    
    while (pt--) {
        int num;
        cin >> num;
        int arr[num];
        
        for (int iter = 0; iter < num; iter++) {
            cin >> arr[iter];
        }
        
        if(num==3){
            if(arr[1]>max(arr[2],arr[0]) || arr[1]<min(arr[2],arr[0]) ){
                cout<<"NO"<<endl;
            }else
                cout<<"YES"<<endl;
                
            continue;
        }
        
        if(num==2){
            if(arr[0]<=arr[1]){
                cout<<"YES"<<endl;
            }else{
                cout<<"NO"<<endl;
            }
            continue;
        }
        
        cout<<"YES"<<endl;
    }
    
    return 0;
}
