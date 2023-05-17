// Question Link: https://www.interviewbit.com/problems/collatz-conjecture/

/*
Collatz Conjecture:

Problem Description:
Given two integers A and B, where A is the first element of the sequence then find Bth element of the sequence.
If the kth element of the sequence is X then k+1th element calculated as:
if X is even then next element is X/2.
else next element is 3×X + 1.

Problem Constraints:
1 <= A <= 109
1 <= B <= 105

Input Format:
Given two integers A and B.

Output Format:
Return an integer.

Example Input:
Input 1:
A = 1
B = 3
Input 2:
A = 5
B = 6

Example Output:
Output 1:
2
Output 2:
1

Example Explanation:
Explanation 1:
 The sequence is as follows 1 -> 4 -> 2
Explanation 2:
The sequence is as follows 5 -> 16 -> 8 -> 4 -> 2 -> 1
*/



long Solution::solve(int A, int B) {
    long x=A;
    
    for(int i=0; i<B-1; i++){
        if(x%2 == 1)
            x = x*3+1;
        else
            x /= 2;
    }
    
    return x;
}
