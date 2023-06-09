// Question Link: https://www.codechef.com/problems/RIGHTTHERE

/*
Problem:

If you wanna party, if you, if you wanna party
Then put your hands up

Chef wants to host a party with a total of N people.
However, the party hall has a capacity of X people. Find whether Chef can host the party.

Input Format:
The first line of input will contain a single integer T, denoting the number of test cases.
Each test case consists of two space-separated integers N and X — the total number of people and the capacity of the party hall.

Output Format:
For each test case, output on a new line, YES, if Chef can host the party and NO otherwise.
Each character of the output may be printed in either uppercase or lowercase. That is, the strings NO, no, nO, and No will be treated as equivalent.

Constraints:
1 ≤ T ≤ 100
1 ≤ N, X ≤ 10

Sample 1:
Input
4
2 5
4 3
6 6
10 9
Output
YES
NO
YES
NO

Explanation:
Test case 1: Chef wants to host a party with 2 people. Since the capacity of the hall is 5, he can host the party.
Test case 2: Chef wants to host a party with 4 people. Since the capacity of the hall is 3, he can not host the party.
Test case 3: Chef wants to host a party with 6 people. Since the capacity of the hall is 6, he can host the party.
Test case 4: Chef wants to host a party with 10 people. Since the capacity of the hall is 9, he can not host the party.
*/



// Time Complexity = O(t), Space Complexity = O(1)
#include <iostream>
using namespace std;

int main() {
	// your code goes here
	int t;
	cin >> t;
	
	while(t--) {
	    int n, x;
	    cin >> n >> x;
	    
	    (n <= x) ? cout << "YES\n" : cout << "NO\n";
	}
	
	return 0;
}










