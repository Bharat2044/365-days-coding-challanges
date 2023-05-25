// Question Link: https://www.interviewbit.com/problems/sum-of-7-s-multiple/

/*
Sum of 7's Multiple:

Problem Description:
Given a range [A, B], find sum of integers divisible by 7 in this range.

Problem Constraints:
1 <= A <= B <= 109

Input Format:
First argument is an integer A.
Second argument is an integer B.

Output Format:
Return an integer.

Example Input:
Input 1:
A = 1
B = 7
Input 2:
A = 99
B = 115

Example Output:
Output 1:
7
Output 2:
217

Example Explanation:
Explanation 1:
Integers divisible by 7 in given range are {7}.
Explanation 2:
Integers divisible by 7 in given range are {105, 112}.
*/


long Solution::solve(int A, int B) {
    /*int ans = 0;
    
    for(long long int i=A ; i<=B ; i++){
        if(i%7 == 0) 
            ans += i;
    }    
    return ans;*/
    
    
    long long int first = (A % 7 == 0) ? A : A + (7 - A % 7);
    long long int last = (B % 7 == 0) ? B : B - (B % 7);
    long long int n = (last - first) / 7 + 1;
    long long int ans = n * (2 * first + (n - 1) * 7) / 2;
    
    return ans;      
}
