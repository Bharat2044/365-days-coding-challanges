// Question Link: https://www.codechef.com/problems/THREETOPICS


// Time Complexity = O(1), Space Complexity = O(1)
#include <iostream>
using namespace std;

int main() {
	// your code goes here
	int a, b, c, x;
	cin >> a >> b >> c >> x;
	
	if(x==a || x==b || x==c)
	    cout<<"Yes\n";
	
	else
	    cout<<"No\n";
	
	return 0;
}
