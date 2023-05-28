// Question Link: https://www.codechef.com/problems/ASET002

/*
Problem:
Given an integer, n, perform the following conditional actions:

If n is odd, print Weird
If n is even and in the inclusive range of 2 to 5, print Not Weird
If n is even and in the inclusive range of 6 to 20, print Weird
If n is even and greater than 20, print Not Weird

Input Format:
A single line containing a positive integer, n.

Constraints:
n lies between 1 and 100

Input:
17

Output:
Weird
*/


// Time Complexity = O(1), Space Complexity = O(1)
#include <iostream>
using namespace std;

int main() {
	// your code goes here
	int n;
	cin >> n;
	
	if(n & 1)
	    cout << "Weird" << endl;
	else if((n&1)==0 && (n>=2 && n<=5) || n>20)
	    cout << "Not Weird" << endl;
	else if((n&1)==0 && n>=6 && n<=20)
	    cout << "Weird" << endl;
	    
	return 0;
}
