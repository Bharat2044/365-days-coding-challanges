// Question Link: https://www.codechef.com/problems/PINS


#include <bits/stdc++.h>
using namespace std;

int main()
{
	int t;
	cin >> t;
	
	while (t--)
	{
		int n;
		cin >> n;
		
		string x = "1";
		x += string(n / 2, '0');
		
		cout << 1 << " " << x << endl;
	}
	
	return 0;
}
