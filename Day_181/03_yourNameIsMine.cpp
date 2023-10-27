// Question Link: https://www.codechef.com/problems/NAME2


#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    
    while(t--){
        string s1, s2;
        cin>>s1>>s2;
        
        int i;
        if(s1.length()>s2.length()){
            swap(s1,s2);
        }
        
        stack<char> stk;
       
        for(i=0;i<s1.length();i++){
            stk.push(s1[i]);
        }
        
        for(i=s2.length()-1;i>=0;i--){
            if(!stk.empty() && (s2[i]==stk.top())){
                stk.pop();
            }
        }
        
        if(stk.empty()){
            cout<<"YES"<<endl;
            continue;
        }
   
        cout<<"NO"<<endl;
    }
    
    return 0;
}
