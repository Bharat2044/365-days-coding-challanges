// Question Link: https://www.codechef.com/problems/MIME2


#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
    int n,q;
    cin>>n>>q;
    map<string,string> mp;
    
    while(n--){
        string s1,s2;
        cin>>s1>>s2;
        mp[s1] = s2;
    }
    
    while(q--){
        string s;
        cin>>s;
        
        string sub;
        bool check=false;
        
        for(int i=s.length()-1;i>=0;i--){
            if(s[i]!='.'){
                sub+=s[i];
            }
            else if(s[i]=='.'){
                check=true;
                break;
            }
        }
        
        reverse(sub.begin(),sub.end());
        if(check && mp.count(sub)){
            cout<<mp[sub]<<endl;
        }
        else{
            cout<<"unknown"<<endl;
        }
    }
    
    return 0;
}
