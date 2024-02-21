// Question Link: https://www.codechef.com/problems/EATTWICE


#include <iostream>
using namespace std;

int main() {
    int t;
    cin>>t;
    
    while(t--){
        int n,m;
        cin>>n>>m;
        long long int d[n],v[n];
        
        for(int i=0;i<n;i++){
            cin>>d[i]>>v[i];
        }
        
        long long int max1=0,max2=0,p=0;
        
        for(int i=0;i<n;i++){
            if(d[i]<=m && v[i]>max1){
                max1=v[i];
                p=d[i];
            }
        }
        
        for(int i=0;i<n;i++){
            if(d[i]<=m && v[i]>max2 && d[i]!=p){
                max2=v[i];
            }
        }
        cout<<max1+max2<<endl;
    }
    
	return 0;
}
