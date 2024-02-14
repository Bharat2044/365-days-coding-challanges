// Question Link: https://www.codechef.com/problems/BIGARRAY


#include <iostream>
using namespace std;

int main() {
    int t;
    cin>>t;
    
    while(t--){
        long long int n,s;
        cin>>n>>s;
        
        long long int k=(n*(n+1))/2;
        int con=0;
        long long int p=k-s;
        
        if(p>=1&&p<=n){
            cout<<p<<endl;
        }
        else 
            cout<<-1<<endl;
    }
    
	return 0;
}
