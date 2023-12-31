// QUestion Link: https://www.interviewbit.com/problems/or-equal-xor/

/*
OR equal XOR

Problem Description:
You are given an integer A. Find the number of ordered pairs (x, y) such that 0 ≤ x, y < 2A and they satisfy the following condition-
(x ^ y) = (x | y).
In other words, the bitwise XOR of both these numbers is equal to the bitwise OR of these numbers. Since the answer can be large, calculate it modulo 109 + 7.

Problem Constraints:
0 <= A <= 105

Input Format:
The first and only argument contains an integer A.

Output Format:
Return a single integer denoting the answer.

Example Input:
Input 1:
0
Input 2:
1

Example Output:
Output 1:
1
Output 2:
3

Example Explanation:
Explanation 1:
Valid pair - (0, 0)
Explanation 2:
Valid pairs - (0, 0), (0, 1), (1, 0)
*/


int expo(int a,int b,int mod){
    int ans=1;
    while(b)
    {
        if(b&1)
            ans=(ans*1ll*a)%mod;
        a=(a*1ll*a)%mod;
        b>>=1;
    }
    return ans;
}
int Solution::solve(int A) {
    return expo(3, A, 1e9 + 7);
}
