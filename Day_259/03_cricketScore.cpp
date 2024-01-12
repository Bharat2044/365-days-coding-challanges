// Question Link: https://www.codechef.com/problems/CRICSCR


#include<bits/stdc++.h>
using namespace std;

int main(){
  long long n, flag = 1;
  cin >> n;

  long long r, w, pr, pw;
  pw=pr=0;

  for(long long i = 0; i < n; i++){
      cin >> r >> w;

      if((r < pr) || (w ==10 && r>pr && w>pw && i<n-1) || (w<pw)){
          flag = 0;
          break;
      }
      pw=w;pr=r;
  }


  if(flag==1)
      cout << "YES\n";
  else 
      cout << "NO\n";

  
  return 0;
}
