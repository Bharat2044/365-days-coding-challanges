// Question Link: https://www.codechef.com/problems/CHEFCH


#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin>>t;
    
    while(t--){
        string s;
        int m1=0,m2=0;
        cin>>s;
        
        for(int i=0;i<s.size();i++){
            char tempo;
            tempo=(i%2==0?'+':'-');
            
            if(s[i]!=tempo)
              m1++;
        }
    
        for(int i=0;i<s.size();i++){
            char tempo;
            tempo=(i%2==0?'-':'+');
            
            if(s[i]!=tempo)
              m2++;
        }
        
        cout<<min(m1,m2)<<endl;
    }
    
    return 0;
}
