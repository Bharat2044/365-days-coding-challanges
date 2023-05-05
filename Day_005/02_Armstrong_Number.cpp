/*
Armstrong Number:

Problem Description:
Given an integer A, check if it is an Armstrong number of not.
An Armstrong number is a number that is the sum of its own digits each raised to the power of the number of digits.

Problem Constraints:
1 <= A <= 109

Input Format:
Given an integer A.

Output Format:
Return an integer.

Example Input:
Input 1:
A = 371
Input 2:
A = 123

Example Output:
Output 1:
1
Output 2:
0

Example Explanation:
Explanation 1:
3×3×3 + 7×7×7 + 1×1×1 = 371
Explanation 2:
1×1×1 + 2×2×2 + 3×3×3 != 123
*/



int Solution::solve(int A) {        
    int sum = 0;    
    int x = A, y = A;
    
    int count = 0;
    while(x > 0) {
        count++;
        x /= 10;
    }
    
    while(y > 0) {
        int d = y%10;
        sum += pow(d, count);
        y /= 10;
    }
    
    return (A == sum);
}
