// Question Link: https://www.interviewbit.com/problems/divide-integers/

/*
Divide Integers

Problem Description:
Divide two integers A and B, without using multiplication, division, and mod operator.
Return the floor of the result of the division.

Also, consider if there can be overflow cases. For overflow cases, return INT_MAX.
Note: INT_MAX = 2^31 - 1

Problem Constraints:
INT_MIN <= A, B <= INT_MAX
B != 0

Input Format:
The first argument is an integer A.
The second argument is an integer B.

Output Format:
Return an integer equal to A / B.

Example Input:
A = 5
B = 2

Example Output:
2

Example Explanation:
A = 5, B = 2, therefore A / B = 5 / 2 = 2.5
Taking the floor value of 2.5 is 2
*/
  


int Solution::divide(int A, int B) {
    int s = 0;
    
    if((A<0 && B<0) || (A>=0 && B>=0))
        s = 1;
    else
        s =- 1;
    
    if(B == 1)
        return A;
        
    A = A==INT_MIN ? INT_MAX : abs(A);
    B = B==INT_MIN ? INT_MAX : abs(B);

    long long int ans = exp(log(A) - log(B)) + 0.0000000001;
    ans = (ans>INT_MAX) ? INT_MAX : ans;
    
    return ans*s;
}
