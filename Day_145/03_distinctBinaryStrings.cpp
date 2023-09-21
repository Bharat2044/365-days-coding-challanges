// Question Link: https://www.codechef.com/problems/BINSTRING


#include <bits/stdc++.h>
using namespace std;

int main() {
      int t;
      cin >> t;
      while(t--)
      {
          int n;
          cin >> n;
          string s;
          cin >> s;
          
          int count = 0;
          
          for(int i=0;i<n;i++)
          {
              if(s[i]==s[i+1])
              {
                  count++;
              }
              
              else continue;
          }
          
          cout << n-count << endl;
         
       
      }
	return 0;
}
