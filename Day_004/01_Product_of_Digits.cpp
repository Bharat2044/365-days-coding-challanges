// Question Link: https://www.interviewbit.com/problems/product-of-digits/

/*
Product of Digits:

Problem Description:
Given an integer A.
Find the product of all of it's digits.

Problem Constraints:
0 <= A <= 109

Input Format:
Given an integer.

Output Format:
Return an integer.

Example Input:
Input 1:
A = 111
Input 2:
A = 123

Example Output:
Output 1:
1
Output 2:
6

Example Explanation:
Explanation 1:
111 -> 1×1×1 = 1
Explanation 2:

123 -> 1×2×3 = 6
*/


// Time Complexity = O(logA), Space Complexity = O(1)
int Solution::solve(int A) {
    if(A == 0)
        return 0;
        
    int ans = 1;
    
    while(A != 0) {
        int d = A%10;        
        ans *= d;
        A /= 10;
    }
    
    return ans;
}
