// Question Link: https://www.codechef.com/problems/STONES


#include <iostream>
#include<string>
using namespace std;

int main() {
	// your code goes here
	int t; 
	cin>>t;
	
	while(t--){
	    string j, s;
	    cin>>j>>s;
	    
	    int ans, count = 0;
	    ans = s.find_first_of(j);
	    
	    while(ans != std :: string :: npos)
	    {
	        count++;
	        ans = s.find_first_of(j, ans+1);
	    }
	    
	    cout<<count<<endl;
	}
	return 0;
}
