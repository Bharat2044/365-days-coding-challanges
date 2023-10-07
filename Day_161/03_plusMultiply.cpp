// Question Link: https://www.codechef.com/problems/PLMU


#include <iostream>
using namespace std;

int main() {
    int t;
    cin>>t;
    
    while(t--){
        int n; 
        cin>>n;
        
        int arr[n];
        int c1 = 0,c2 = 0;
        
        for(int i=0;i<n;i++){
            cin>>arr[i];
            
            if(arr[i] == 0){
                c1++;
            }
            if(arr[i] == 2){
                c2++;
            }
        }
        
        cout<<c1*(c1-1)/2 + c2*(c2-1)/2<<endl;
        
    }
    
	return 0;
}
