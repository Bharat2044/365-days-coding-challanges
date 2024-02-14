// Question Link: https://www.codechef.com/problems/LCM_GCD


#include <iostream>
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
int MOD = 1e9+7;

int solution(int a, int b) {
    return a-__gcd(a,b);
}

int main() {

	int T; 
	cin >> T;
	
	int a,b;
	
	while(T--) {
	    cin >> a >> b;
	    
	    auto res = solution(a,b);
	    cout << res << endl;
	}
	
	return 0;
}
