// Question Link: https://www.codechef.com/problems/BUGCAL


#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >>t;
    
    for(int i=0;i<t;i++){
        long int e,f;
        cin >>e>>f;
        
        long int a=max(e,f);
        long int b=min(e,f);
        
        string s,d;
        long int r=0;
        long int k=0;
        
        while(a!=0){
            long int sum=b%10+a%10;
            b/=10;
            a/=10;
            r+=(sum%10)*(pow(10,k));
            k++;
        }
        cout<<r<<endl;
    }
    
    return 0;
}
