// Question Link: https://www.codechef.com/problems/RECNDSTR


#include <iostream>
using namespace std;

string left_shift(string s) {
    int len = s.length();
    string s1;
    s1 = s.substr(1,len) + s[0];
  
    return s1;
} 

string right_shift(string s) {
    int len = s.length();
    string s1;
    s1 = s[len-1] + s.substr(0,len-1);
  
    return s1;
}

int main() {
    int t;
    cin >> t;
    while(t--) {
        string s;
        cin >> s;
      
        if(left_shift(s) == right_shift(s)) 
            cout << "YES" << endl;
        
        else 
            cout << "NO" << endl;        
    }
  
	return 0;
}
