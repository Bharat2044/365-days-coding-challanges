// Question Link: https://www.interviewbit.com/problems/length-of-last-word/

/*
Length of Last Word:

Problem Description:
Given a string s consists of upper/lower-case alphabets and empty space characters ' ', return the length of last word in the string.

If the last word does not exist, return 0.

Note: A word is defined as a character sequence consists of non-space characters only.

Please make sure you try to solve this problem without using library functions. Make sure you only traverse the string once.

Problem Constraints:
1 <= |A| <= 106

Input Format:
The first argument is a string A

Output Format:
Return an integer denoting the length of the last word in the string.

Example Input:
Input 1:
A = " hello world "
Input 2:
A = "InterviewBit"

Example Output:
Output 1:
5
Output 2:
12

Example Explanation:
Explanation 1:
"world" is the last word of size 5
Explanation 2:
"InterviewBit" is the last word of size 12
*/



int Solution::lengthOfLastWord(const string A) {
    int len = 0;
    int n = A.length();
    int k = n-1;
    
    while(k>=0 && A[k]==' ')
       k--;
    
    for(int i=0; i<=k; i++) {
        
        if(A[i]>=65 && A[i]<=90)
           len++;        
        else if(A[i]>=97 && A[i]<=122)
            len++;        
        else
           len = 0;
    }
    
    return len;
}
