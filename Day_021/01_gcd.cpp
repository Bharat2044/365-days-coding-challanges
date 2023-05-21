// Question Link: https://www.interviewbit.com/problems/greatest-common-divisor/

/*
Greatest Common Divisor:

Problem Description:
Given 2 non-negative integers A and B, find gcd(A, B).
GCD of 2 integers m and n is defined as the greatest integer g such that g is a divisor of both m and n.
Both A and B fit in a 32-bit signed integer.

NOTE: DO NOT USE LIBRARY FUNCTIONS

Problem Constraints:
0 <= A <= 109
0 <= B <= 109

Input Format:
The first argument is an integer A.
The second argument is an integer B.

Output Format:
Return the Greatest Common Divisor of A and B

Example Input:
Input 1:
A = 6
B = 9

Example Output:
Output 1:
3

Example Explanation:
Explanation 1:
3 is the GCD of 6 and 9
*/


// Time Complexity = O(min(log(A,B))), Space Complexity = O(1)
int Solution::gcd(int A, int B) {
    // return __gcd(A, B);
    
    while(B) {
        int rem = A%B;
        A = B;
        B = rem;
    }
    
    return A;    
}
