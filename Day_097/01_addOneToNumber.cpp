// Question Link: https://www.interviewbit.com/problems/add-one-to-number/

/*
Add One To Number

Problem Description:
Given a non-negative number represented as an array of digits, add 1 to the number ( increment the number represented by the digits ).

The digits are stored such that the most significant digit is at the head of the list.

NOTE: Certain things are intentionally left unclear in this question which you should practice asking the interviewer. For example: 
for this problem, following are some good questions to ask :

Q : Can the input have 0's before the most significant digit. Or in other words, is 0 1 2 3 a valid input?
A : For the purpose of this question, YES
Q : Can the output have 0's before the most significant digit? Or in other words, is 0 1 2 4 a valid output?
A : For the purpose of this question, NO. Even if the input has zeroes before the most significant digit.

Problem Constraints:
1 <= |A| <= 106
0 <= Ai <= 9

Input Format:
First argument is an array of digits.

Output Format:
Return the array of digits after adding one.

Example Input:
Input 1:
[1, 2, 3]

Example Output:
Output 1:
[1, 2, 4]

Example Explanation:
Explanation 1:
Given vector is [1, 2, 3].
The returned vector should be [1, 2, 4] as 123 + 1 = 124.
*/



vector<int> Solution::plusOne(vector<int> &A) {
    int n = A.size();

    // If the last element is less than 9, than adding 1 will not generate any carry so last element of array will be increased by 1, and rest will remain unchanged.
    if(A[n-1] < 9)
        A[n-1] = A[n-1]+1;

    // If last element is 9 than we will have to keep track of carry
    else {
        A[n-1] = 0;
        int carry = 1;

        for(int i=n-2; i>=0; i--){
            long long int sum = A[i]+carry;
            A[i] = sum%10;
            carry = sum/10;
        }
        
        if(carry > 0)
            A.insert(A.begin(), carry);
    }

    // if we have any leading 0, we will remove it.
    int i = 0;

    while (A[0] == 0 && i < n-1) {
        A.erase(A.begin());
        i++;
    }
    
    return A;
}
