// Question Link: https://www.interviewbit.com/problems/palindrome-integer/ 

/*
Palindrome Integer:

Problem Description:
Determine whether an integer is a palindrome. Do this without extra space.

A palindrome integer is an integer x for which reverse(x) = x where reverse(x) is x with its digit reversed. Negative numbers are not palindromic.

Problem Constraints
INT_MIN <= A <= INT_MAX

Input Format:
The first argument is an integer A.

Output Format
Return 1 if A is a Palindrome Integer else return 0.

Example Input:
Input 1:
A = 12121
Input 2:
A = 123

Example Output:
Output 1:
1
Output 2:
0

Example Explanation:
Explanation 1:
 12121 when reversed will be 12121, and 12121 = 12121, hence a palindrome number.
Explanation 2:
 123 when reversed will be 321, and 123 != 321, hence not a palindrome number
*/


// Time Complexity = O(logA), Space Complexity = O(1)
int Solution::isPalindrome(int A) {
    if(A < 0)
        return 0;
        
    int temp = A, rev = 0;
    
    while(temp) {
        rev = (rev*10) + (temp%10);
        temp /= 10;
    }
    
    return (rev == A);
}
