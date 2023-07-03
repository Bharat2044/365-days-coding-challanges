// Question Link: https://www.codechef.com/problems/BRACKETS


#include <iostream>
#include<cmath>
#include<cstring>
using namespace std;

int main() {
	// your code goes here
    int t;
    cin >> t;
  
    while(t--) {
        string s;
        cin >> s;
      
        int b = 0;
        int mb = 0;
      
        for(int i = 0; i < s.size(); i++){
            if(s.at(i) == '(')
                b++;
            else if(s.at(i)== ')')
                b--;
            
            mb = max(mb,b);
        }
        for(int i = 0; i < mb; i++)
            cout<<'(';
        
        for(int i = 0; i < mb; i++)
            cout<<')';
        
        cout<<endl;
    }
	return 0;
}
