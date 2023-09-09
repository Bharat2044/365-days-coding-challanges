// Question Link: https://www.codechef.com/problems/SPLITIT


#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin>>t;
    
    while(t--){
        int n,count=0;
        cin>>n;
        
        string s;
        cin>>s;
        
        for (int i = 0; i < n-1; i++) {
           if(s[i]==s[n-1]){
               count++;
               break;
           }
        }
        
        if(count==0){
            cout << "NO" << std::endl;
        }
        else{
            cout << "YES" << std::endl;
        }
    }
    
	return 0;
}
