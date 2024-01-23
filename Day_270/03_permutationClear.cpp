// Question Link: https://www.codechef.com/problems/PERMCLEAR


#include <bits/stdc++.h>
using namespace std;

int main() {
    // your code goes here
    int t;
    cin>>t;
    
    while(t--){
        int m;
        cin>>m;
       vector<int>v(m);
       
       for(int i=0;i<m;i++){
           cin>>v[i];
       }
       
       int y;
       cin>>y;
       set<int>st;
       
       for(int i=0;i<y;i++){
           int n;
           cin>>n;
           st.insert(n);
       }
       
       for(int i=0;i<m;i++){
           if(st.count(v[i])){
               continue;
           }
           else{
               cout<<v[i]<<" ";
           }
       }
       cout<<endl;
    }
    
    return 0;
}
