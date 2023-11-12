// Question Link: https://www.codechef.com/problems/CHEFCHR


#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    
    while(t--){
        string s;
        cin>>s;
        
        string a="cefh";
        int count=0;
        
        for(int i=0;i<(s.size());i++){
            string str=s.substr(i,4);
            sort(str.begin(),str.end());
            
            if(str==a) 
                count++;
        }
        
        if(count==0) 
            cout<<"normal"<<endl;
        else 
            cout<<"lovely "<<count<<endl;
    }
    
    return 0;
}
