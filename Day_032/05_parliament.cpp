// Question Link: https://www.codechef.com/problems/PARLIAMENT

/*
Problem
An important resolution is being discussed in the Parliament of Chefland. There are N members present in the Parliament out of which X members voted in favour of the resolution and the remaining voted against it.

According to the constitution of Chefland, a resolution is passed if and only if half or more than half the members present in the Parliament vote in favour of the resolution.

Determine if the resolution is passed or not.

Input Format:
The first line contains a single integer T — the number of test cases. Then the test cases follow.
The first and only line of each test case contains two space-separated integers N and X — the total number of members present in the Parliament and the number of members who voted in favour of the resolution.

Output Format:
For each test case, output YES if the resolution is passed. Otherwise, output NO.
You may print each character of YES and NO in uppercase or lowercase (for example, yes, yEs and Yes will be considered identical).

Constraints:
1 ≤ T ≤ 5000
1 ≤ N ≤ 100
0 ≤ X ≤ N

Sample 1:
Input
4
12 6
9 4
9 5
12 0

Output
YES
NO
YES
NO

Explanation:
Test Case 1: The resolution is passed since half the people voted in favour of the resolution.
Test Case 2: The resolution is not passed since less than half the people voted in favour of the resolution.
Test Case 3: The resolution is passed since more than half the people voted in favour of the resolution.
Test Case 4: The resolution is not passed since everybody voted against the resolution.
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
	    
	    (x*2 >= n) ? cout << "YES\n" : cout << "NO\n";
	}
	
	return 0;
}
