// Question Link: https://www.interviewbit.com/problems/modular-expression/

/*
Modular Expression

Problem Description:
Implement pow(A, B) % C.
In other words, given A, B and C, find (AB)%C. 

Problem Constraints:
-106 <= A <= 109
0 <= B <= 109
0 <= C <= 109

Input Format:
The first argument is an integer A.
The second argument is an integer B.
The third argument is an integer C.

Output Format:
Return an integer equal to (AB) % C

Example Input:
A = 2, B = 3, C = 3

Example Output:
2

Example Explanation:
2^3 % 3 = 8 % 3 = 2
*/



long long power(long long A,long long B,long long C)
{
    if(B==0)
    {
        return 1;
    }
    else if(B%2==0)
    {
        return (power(A,B/2,C) * power(A,B/2,C))%C;
    }
    else
    {
        return (A * power(A,B-1,C))%C;
    }
}

int Solution::Mod(int A, int B, int C) {
    if(A==0) 
        return 0;
    
    if(A<0)
    {
        A=(A%C+C)%C;
    }
    
    return power(A,B,C);
}

