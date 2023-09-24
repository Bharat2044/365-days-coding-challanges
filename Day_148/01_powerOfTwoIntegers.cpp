// Question Link: https://www.interviewbit.com/problems/power-of-two-integers/

/*
Power Of Two Integers

Problem Description:
Given a positive integer that fits in a 32-bit signed integer, find if it can be expressed as A^P where P > 1 and A > 0.
A and P both should be integers.

Problem Constraints:
1 <= A <= 109

Input Format:
The first argument is an integer A.

Output Format:
Return an integer, 1 for True, 0 for False

Example Input:
A = 4

Example Output:
1

Example Explanation:
A = 4, it can be written as 2 ^ 2
*/




int Solution::isPower(int A) {
    if(A == 0 or A == 1) 
        return true;

    int p = 2;
    float n = pow(A, (1.0/p));

    while((int)n > 1) {
        if(n - int(n) == 0) 
            return true;
            
        p++;
        n = pow(A, (1.0/ p));
    }

    return false;
}
