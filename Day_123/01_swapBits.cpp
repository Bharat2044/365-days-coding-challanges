// Question Link: https://www.interviewbit.com/problems/swap-bits/

/*
Swap Bits

Problem Description:
Given an integer A.
Swap the Bth and Cth bit from right in binary representation of A.
Return the integer formed.

Problem Constraints:
1 <= A < 230
1 <= B, C <= 30

Input Format:
First argument is an integer A.
Second argument is an integer B.
Third argument is an integer C.

Output Format:
Return an integer.

Example Input:
Input 1:
A = 9
B = 1
C = 2
Input 2:
A = 1
B = 1
C = 3

Example Output:
Output 1:
10
Output 2:
4

Example Explanation:
Explanation 1:
5 -> 101
Swapping 1st and 2nd bit from right gives 110.
Explanation 2:
1 -> 001
Swapping 1st and 3rd bit from right gives 100.
*/



int Solution::solve(int a, int b, int c) {
    b=b-1;
    c=c-1;
    int val1 = (a>>b)&1;

    int val2 = (a>>c)&1;
    if(val1==val2){
        return a;
    }

    if(val1==0&&val2==1){
        a=a|(1<<b);
        a=a^(1<<c);
    }
    else if(val1==1&&val2==0){
        a=a^(1<<b);
        a=a|(1<<c);
    }

    return a;
}
