// Question Link: https://www.codechef.com/problems/MAX2


#include <iostream>
using namespace std;

int main() {
	  int t;
	  cin>>t;
	  
	    string s;
	    cin>>s;
	    int count=0;
	    
	    for(int i=s.length()-1;i>=0;i--){
	      if(s[i]=='0'){
	        count++;
	      }
	      else{
	        break;
	      }
	    }
	    
	    cout << count << endl;
	    
	return 0;
}
