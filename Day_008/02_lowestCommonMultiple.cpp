// Question Link: https://www.interviewbit.com/problems/lowest-common-multiple-lcm/

/*
Lowest Common Multiple (LCM):

Problem Description:
Find Lowest Common Multiple of given two integers.

Problem Constraints:
1 <= A <= 109
1 <= B <= 109

Input Format:
First argument is an integer A.
Second argument is an integer B.

Output Format:
Return an integer.

Example Input:
Input 1:
A = 6
B = 4
Input 2:
A = 1
B = 11


Example Output:
Output 1:
12
Output 2:
11

Example Explanation:
Explanation 1:
12 is the smallest integer which is divisible by 4 and 6 both.
Explanation 2:
11 is the smallest integer which is divisible by 1 and 11 both.
*/



// Time COmplexity = O(log(min(A, B)), SPace Complexity = O(1)
long gcd(int x, int y) {
    
    while(x != y) {
        if(x > y)
            x = x-y;
        else
            y = y-x;
    }
    
    return x;
}

long Solution::solve(int A, int B) {    
    
    // return (A*B)/gcd(A, B);
    return  A/(gcd(A, B))*B;
}
