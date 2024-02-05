// Question Link: https://www.codechef.com/problems/NOTDIVISIBLE


#include <iostream>
using namespace std;

int main() {
    int t,i,j,n;
    cin>>t;
    
    for(i=0;i<t;i++){
        cin>>n;
        
        for(j=0;j<n;j++){
            if(j%2==1){
                cout<<"0"<<" ";
            }
            else cout<<"1"<<" ";
        }
        
        cout<<endl;
    }
    
	return 0;
}
