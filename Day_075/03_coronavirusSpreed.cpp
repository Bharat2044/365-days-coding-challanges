// Question Link: https://www.codechef.com/problems/COVID19


#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;

int main() {
	int t;
	cin >> t;
	while(t--){
	    int n;
	    cin >> n;
	    vector <int> v(n);
	    for (auto &i: v)
	        cin >> i;
	    int temp, mini = INT_MAX, maxi = INT_MIN, count = 1;
	    for (int i = 0; i < n-1; ++i) {
	        temp = abs(v[i + 1] - v[i]);
	        if (temp <= 2)
	            ++count;
	        else {
	            mini = min(mini, count);
	            maxi = max(maxi, count);
	            count = 1;
	        }
	    }
	    mini = min(mini, count);
	    maxi = max(maxi, count);
	    cout << mini << ' ' << maxi << '\n';
    }
    return 0;
}
