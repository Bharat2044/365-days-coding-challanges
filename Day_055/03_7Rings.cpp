// Question Link: https://www.codechef.com/problems/SEVENRINGS

/*
Problem:
Yeah, my receipts be lookin' like phone numbers
If it ain't money, then wrong number

In Chefland, a valid phone number consists of 5 digits with no leading zeros.
For example, 98765,10000, and 71023 are valid phone numbers while 04123,9231, and 872310 are not.

Chef went to a store and purchased N items, where the cost of each item is X.
Find whether the total bill is equivalent to a valid phone number.

Input Format:
The first line of input will contain a single integer T, denoting the number of test cases.
Each test case consists of two space-separated integers N and X — the number of items Chef bought and the cost per item.

Output Format
For each test case, output on a new line, YES, if the total bill is equivalent to a valid phone number and NO otherwise.

Each character of the output may be printed in either uppercase or lowercase. That is, the strings NO, no, nO, and No will be treated as equivalent.

Constraints:
1 ≤ T ≤ 100
1 ≤ N, X ≤ 1000

Sample 1:
Input
4
25 785
402 11
100 100
333 333
Output
YES
NO
YES
NO

Explanation:
Test case 1: Chef bought 25 items, each with cost 785. The total bill is thus, 25⋅785=19625. Since the total bill amount is 5 digits with no leading zeros, it is equivalent to a valid phone number.
Test case 2: Chef bought 402 items, each with cost 11. The total bill is thus, 402⋅11=4422. Since the total bill amount is of 4 digits, it is not equivalent to a valid phone number.
Test case 3: Chef bought 100 items, each with cost 100. The total bill is thus, 100⋅100=10000. Since the total bill amount is 5 digits with no leading zeros, it is equivalent to a valid phone number
Test case 4: Chef bought 333 items, each with cost 333. The total bill is thus, 333⋅333=110889. Since the total bill amount is of 6 digits, it is not equivalent to a valid phone number.
*/



// Time Complexity = O(t), Space Complexity = O(1)
#include <iostream>
using namespace std;

int main() {
	// your code goes here
	int t;
	cin >> t;
	
	while(t--) {
	 int N, X;
	 cin >> N >> X;
	 
	    if((N*X)>9999 && (N*X)<=99999)
	        cout << "YES\n";
	    else
	        cout << "NO\n";
	}
	
	return 0;
}

