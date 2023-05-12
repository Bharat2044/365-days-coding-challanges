// Question Link: https://www.interviewbit.com/problems/bit-flipping/

/*
Bit Flipping:

Problem Description:
Given an integer A.
Write binary representation of the integer without leading zeros.
Flip all bits then return the integer value of the binary number formed.
Flipping means 0 -> 1 and 1 -> 0.

Problem Constraints:
1 <= A <= 109

Input Format:
Given an integer A.

Output Format:
Return an integer.

Example Input:
Input 1:
A = 7
Input 2:
A = 5

Example Output:
Output 1:
0
Output 2:
2

Example Explanation:
Explanation 1:
7 -> 111 -> 000 ->0
Explanation 2:
5 -> 101 -> 010 ->3
*/


// Time Complexity = O(logA), Space Complexity = O(1)
int Solution::solve(int A) {
    
    int ans = log2(A)+1;
    ans = pow(2, ans)-1;
    
    return A^(ans);
}
