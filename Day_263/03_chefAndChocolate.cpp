// Question Link: https://www.codechef.com/problems/CHCHCL


#include <iostream>
using namespace std;

int main() {
    int t , n , m;
    cin>>t ;
    
    for(int i=0 ; i<t ; i++){
        cin>>n >>m;
        
        if((n==1) &&(m!=1)){
            if((m-1)%2==0){
                cout<<"No\n";
            }
            else{
                cout<<"Yes\n";
            }
        }
        else if((m==1) && (n!=1)){
            if((n-1)%2==0){
                cout<<"No\n";
            }
            else{
                cout<<"Yes\n";
            }
        }
        else if((n==1) && (m==1)){
            cout<<"No\n";
        }
        else{
            int count =0;
            count=(m-1)+((n-1)*m);
            if(count%2!=0){
                cout<<"Yes\n";
            }
            else{
                cout<<"No\n";
            }
        }
    }
    
	return 0;
}
