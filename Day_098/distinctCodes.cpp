// Question Link: https://www.codechef.com/problems/DISTCODE


#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int main() {
    int T;
    cin>>T;
    
    while(T--){
        vector <int>v;
        string S;
        cin>>S;
        
        for (int i=0;i<S.size()-1;i++){
                int a = S[i]*100 +S[i+1];
            v.push_back(a);
        }
        
        int c=1;
        sort(v.begin(),v.end());
        
        for (int i=0;i<v.size()-1;i++){
            if (v[i]!=v[i+1])
                c++;
        }
        
        cout<<c<<endl;
    }
    
	return 0;
}
