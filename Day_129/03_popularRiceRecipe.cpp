// Question Link: https://www.codechef.com/problems/TIDRICE


#include<bits/stdc++.h>
using namespace std;

int main() {
    // your code goes here
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        string s;
        map<string,char>ac;
        for(int i=0;i<n;i++){
            char st;
            cin>>s>>st;
           ac[s] = st;
        }
        int total = 0;
        for(auto it : ac){
            if(it.second == '+') total += 1;
            else total += (-1);
        }
        cout<<total<<endl;
    }
    return 0;
}
