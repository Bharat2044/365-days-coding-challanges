// Question Link: https://www.interviewbit.com/problems/number-of-1-bits/

/*
Number of 1 Bits:

Problem Description:
Write a function that takes an integer and returns the number of 1 bits it has.

Problem Constraints:
0 <= A <= 4294967295

Input Format:
First and only argument contains integer A

Output Format:
Return an integer as the answer

Example Input:
Input:  11
    
Example Output:
Output:   3

Example Explanation
Explaination: 11 is represented as 1101 in binary 
*/


int Solution::numSetBits(unsigned int A) {    
    int count = 0;
    
    while(A != 0) {
        int d = A/2;        
        if(A & 1)
            count++;            
         A >>= 1;
    }
    
    return count;
}
