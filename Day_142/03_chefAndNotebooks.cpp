// Question Link: https://www.codechef.com/problems/CNOTE


#include <iostream>
using namespace std;

int main() {
    int t;
    cin>>t;
    
    while(t--){
        int x,y,k,n;
        cin>>x>>y>>k>>n;
        
        int c=x-y;
        int flag=0;
        
        while(n--){
            int a,b;
            cin>>a>>b;
            if(a>=c && b<=k){
            flag=1;
            }
        }
        
        if(flag>0)
            cout<<"LuckyChef"<<endl;
        else 
            cout<<"UnluckyChef"<<endl;
    }
    
	return 0;
}
