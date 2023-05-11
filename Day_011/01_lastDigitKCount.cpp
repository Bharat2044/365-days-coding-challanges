// Question Link: https://www.interviewbit.com/problems/last-digit-k-count/

/*
Last digit K count:

Problem Description:
Find the number of integers in range [A, B] with last digit C.

Problem Constraints:
1 <= A <= B <= 109
0 <= C <= 9

Input Format:
Given three integers A, B and C.

Output Format:
Return an integer.

Example Input:
Input 1:
A = 11, B = 111, C = 1
Input 2:
A = 1, B = 9, C = 0

Example Output
Output 1:
11
Output 2:
0

Example Explanation:
Explanation 1:
The integers are 11, 21, 31, 41, 51, 61, 71, 81, 91, 101, 111
Explanation 2:
There are no integers in the range with last digit 0.
*/


int Solution::solve(int A, int B, int C) {
    
    while(A<=B && A%10!=C)
        A++;
   
    if(A>B)
        return 0;

    int n = (B-A)/10 + 1;

    return n;
}

// Gives TLE
/*int Solution::solve(int A, int B, int C) {
    int count = 0;
    
    for(int i=A; i<=B; i++) {
        int x = i;
        
        if((x%10) == C)
            count++;
    }
    
    return count;
}*/
