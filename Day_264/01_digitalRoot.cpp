// Question Link: https://interviewbit.com/problems/digital-root/

/*
Digital Root

Problem Description:
Given an integer A.
Find the digital root of A.
Digital root is the repeated sum of digits of untill there is only one digit left.

Problem Constraints:
1 <= A <= 109

Input Format:
Given an integer A.

Output Format:
Return an integer.

Example Input:
Input 1:
A = 99
Input 2:
A = 100

Example Output:
Output 1:
9
Output 2:
1

Example Explanation:
Explanation 1:
99 -> 9+9 = 18 -> 1+8 = 9
Explanation 2:
100 -> 1+0+0 = 1
*/



int Solution::solve(int A) {
    int temp = A % 9;
    return temp == 0 ? 9 : temp;
}
