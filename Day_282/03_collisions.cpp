// Question Link: https://www.codechef.com/problems/LCOLLIS


#include<bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin>>t;
    
    while(t--) {
        int a,b;
        cin>>a>>b;
        
        vector<string> v;
        
        for(int i=0;i<a;i++) {
            string e;
            cin>>e;
            v.push_back(e);
        }
        
        int z=0;
        for(int i=0;i<b;i++) {
            int y=0;
            
            for(int j=0;j<a;j++) {
                int  x=v[j][i]-48;
                y=y+x;
            }
            z=z+y*(y-1)/2;
        
        }
        
        cout<<z<<endl;
    }
        
    return 0;
}
