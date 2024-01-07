// Question Link: https://www.codechef.com/problems/BFRIEND


#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin>>t;
    
    while(t--){
        long long N,a,b,c;
        cin>>N;
        cin>>a;
        cin>>b;
        cin>>c;
        
        long long k;
        cin>>k;
        int min=abs(k-b)+abs(a-k);
        
       for(long long i=1;i<=N-1;i++){
           long long k;
            cin>>k;
            
            int mind=abs(k-b)+abs(a-k);
            if(mind<min){
                min=mind;
            }           
       } 
      
       cout<<min+c<<endl;
    }

    return 0;
}
