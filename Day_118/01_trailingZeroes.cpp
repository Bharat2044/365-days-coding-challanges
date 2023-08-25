// Question Link: https://www.interviewbit.com/problems/trailing-zeroes/

/*
Trailing Zeroes

Problem Description:
Given an integer A, count and return the number of trailing zeroes.

Problem Constraints:
1 <= A <= 109

Input Format:
First and only argument is an integer A.

Output Format:
Return an integer denoting the count of trailing zeroes.

Example Input:
Input 1:
 A = 18
Input 2:
 A = 8
 
Example Output:
Output 1:
 1
Output 2:
 3

Example Explanation:
Explanation 1:
 18 in binary is represented as: 10010, there is 1 trailing zero.
Explanation 2
 8 in binary is represented as: 1000, there are 3 trailing zeroes.
*/



int Solution::solve(int A) {
     int x, count = 0;
     
    while(A != 0){
        //if last bit is 0 then x will be 0 otherwise x will be 1   
        x = A&1;
        
        //checking last digit
        if(x==0) 
            count++;
        else 
            break;
            
        //performing right shift by 1
        A >>= 1;
    }
    
    return count;
}
