// Question Link: https://www.codechef.com/problems/LCPESY


#include <iostream>
#include <algorithm>
#include <cstring>
#include <map>
using namespace std;

int main() {
	int t;
	cin>>t;
	
	while(t--){
	    string s1,s2;
	    int c=0;
	    
	    cin>>s1>>s2;
	    map <char,int> m1,m2;
	    
	    for(int i=0;i<s1.size();i++){
	        m1[s1[i]]++;
	    }
	    
	    for(int i=0;i<s2.size();i++){
	       m2[s2[i]]++; 
	    }
	    
	    for(auto i:m1){
	      for(auto j:m2){
	          if(i.first==j.first){
	              c+=min(i.second,j.second);
	          }
	      }
	    }
	    
	    cout<<c<<endl;
	}
	
	return 0;
}
