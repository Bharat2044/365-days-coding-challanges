// Question Link: https://www.codechef.com/problems/PLZLYKME


#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >>t;
    
    for(int i=0;i<t;i++){
        double l,d,s,c;
        cin >>l>>d>>s>>c;
        
        double sum=s*(powl(c+1,d-1));
        
        if(sum>=l){
            cout<<"ALIVE AND KICKING"<<endl;
        }
        else{
            cout<<"DEAD AND ROTTING"<<endl;
        }
    }
    
    return 0;
}
