// Question Link: https://www.codechef.com/problems/OJUMPS


#include <iostream>
using namespace std;
#define ll long long
int main() {
	ll a;
	cin >> a;
	ll b = a / 6;
	ll c = b * 6;
	if(a % 6 == 0)
	 cout << "yes" << endl;
	else{ 
	if(c + 1 == a || c + 3 == a || c + 6 == a)
	 cout << "yes" << endl;
	else
	 cout << "no" << endl;
	}
	return 0;
}
