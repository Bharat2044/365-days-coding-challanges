// Question Link: maximum and minimum element of an array

/*
Problem:
Chef took an examination two times. In the first attempt, he scored X marks while in the second attempt he scored Y marks. According to the rules of the examination, the best score out of the two attempts will be considered as the final score.

Determine the final score of the Chef.

Input Format:
The first line contains a single integer T — the number of test cases. Then the test cases follow.
The first line of each test case contains two integersX and Y — the marks scored by Chef in the first attempt and second attempt respectively.

Output Format:
For each test case, output the final score of Chef in the examination.

Constraints:
1 ≤ T ≤ 1000
0 ≤ X, Y ≤ 100

Sample 1:
Input
4
40 60
67 55
50 50
1 100
Output
60
67
50
100
Explanation:
Test Case 1: The best score out of the two attempts is 60.
Test Case 2: The best score out of the two attempts is 67.
Test Case 3: The best score out of the two attempts is 50.
*/



// Time Complexity = O(t), SC = O(1)
#include <iostream>
using namespace std;

int main() {
	int t, x, y;
	cin >> t;
	
	while(t--) {
      cin >> x >> y;

      (x > y) ? cout << x << "\n" : cout << y << "\n";
	}
	
	return 0;
}
