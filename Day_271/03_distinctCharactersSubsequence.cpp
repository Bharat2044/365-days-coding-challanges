// Question Link: https://www.codechef.com/problems/DISCHAR


#include <bits/stdc++.h>
using namespace std;

int main() {
      int t;
      cin >> t;
      
      while(t--)
      {
          string s;
          cin >> s;
          
          int n = s.size();
          unordered_set<char>v;
          
          for(int j=0;j<n;j++)
          {
              v.insert(s[j]);
          }
          
          cout << v.size() << endl;
    }
     
	return 0;
}
