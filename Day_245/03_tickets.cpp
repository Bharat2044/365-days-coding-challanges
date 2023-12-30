// Question Link: https://www.codechef.com/problems/TICKETS5


#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	int t;
	cin >>t;
	while(t--){
	    string s;
	    cin >> s;
	    unordered_set<int> v;
	    for(int i=0; i< s.length(); i++){
	        v.insert(int(s[i]));
	    }
	   
	    if(v.size() != 2){
	        cout << "NO"<< endl;
	    }
	    else{
	        cout << "YES"<<endl;
	    }
	}
	
	return 0;
}
