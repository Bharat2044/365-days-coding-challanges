// Question Link: https://www.codechef.com/problems/DONDRIVE

/*
Problem:
A blood drive aims to collect N number of blood donations.
The drive has collected X donations so far. Find the remaining number of donations needed to reach the target.

Input Format:
The first line of input will contain a single integer T, denoting the number of test cases.
Each test case contains two space-separated integers N and X — the number of required donations and the number of collected donations, respectively.

Output Format:
For each test case, output on a new line, the remaining number of donations needed to reach the target.

Constraints:
1 ≤ T ≤ 200
1 ≤ X ≤ N ≤ 20

Sample 1:
Input
4
5 2
3 3
5 4
7 5
Output
3
0
1
2

Explanation:
Test case 1: The drive aims to collect 5 donations and has collected 2 already. Thus, they need to collect 3 more donations to reach the target.
Test case 2: The drive aims to collect 3 donations and has collected 3 already. Thus, they need to collect no more donations to reach the target.
Test case 3: The drive aims to collect 5 donations and has collected 4 already. Thus, they need to collect 1 more donation to reach the target.
Test case 4: The drive aims to collect 7 donations and has collected 5 already. Thus, they need to collect 2 more donations to reach the target.
*/



// Time Complexity = O(t), Space Complexity = O(1)
#include <iostream>
using namespace std;

int main() {
	// your code goes here
	int t;
	cin >> t;
	
	while(t--){
	    int a, b;
	    cin >> a >> b;
	    
	    cout << (a-b) << "\n";
	}
	
	return 0;
}
