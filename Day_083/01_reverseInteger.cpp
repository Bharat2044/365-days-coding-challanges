// Question Link: https://www.interviewbit.com/problems/reverse-integer/

/*
Reverse integer

Problem Description:
You are given an integer N and the task is to reverse the digits of the given integer. Return 0 if the result overflows and does not fit in a 32 bit signed integer

Look at the example for clarification.

Problem Constraints:
N belongs to the Integer limits.

Input Format:
Input an Integer.

Output Format:
Return a single integer denoting the reverse of the given integer.

Example Input:
Input 1:
 x = 123

Input 2:
 x = -123

Example Output:
Output 1:
 321

Ouput 2:
 -321

Example Explanation:
 If the given integer is negative like -123 the output is also negative -321.
*/




int Solution::reverse(int A) {
    if(A==INT_MIN)
        return 0;
  
    bool neg = A<0 ? true : false;
    if(neg)
        A*=-1;
    string s = to_string(A);
    int n = s.length();
  
    for(int i=0; i<n/2; i++)
    {
        char temp = s[i];
        s[i] = s[n-1-i];
        s[n-1-i] = temp;
    }
  
    long long int B=0;
    for(int i=n-1; i>=0; i--)
        B += (int(s[i]-'0'))*pow(10,n-1-i);
    
    if(B>INT_MAX)
        return 0;
    if(neg)
        B*=-1;
        
    return int(B);
}
