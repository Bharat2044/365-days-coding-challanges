// Question Link: https://www.codechef.com/problems/XORPAL


#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >>t;
    
    for(int i=0;i<t;i++){
        int n;
        cin >>n;
        
        string s;
        cin >>s;
        
        int m,l;
        m=l=0;
        
        for(int j=0;j<s.length();j++){
            if(s[j]=='1'){
                m++;
            }
            else{
                l++;
            }
        }
        
        if(s.length()%2==0){
            if(m%2==0){
                cout<<"YES"<<endl;
            }
            else if(m==l){
                cout<<"YES"<<endl;
            }
            else{
                cout<<"NO"<<endl;
            }
        }
        else{
            cout<<"YES"<<endl;  
        }
    }
    
    return 0;
}
