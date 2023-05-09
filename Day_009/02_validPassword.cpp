// Question Link: https://www.interviewbit.com/problems/valid-password/

/*
Valid Password:

Bookmark
Asked In:
Problem Description:
Given a password as a character array A.
Check if it is valid or not.
Password should have at least one numerical digit(0-9).
Password's length should be in between 8 to 15 characters.
Password should have at least one lowercase letter(a-z).
Password should have at least one uppercase letter(A-Z).
Password should have at least one special character ( @, #, %, &, !, $, *).

Problem Constraints:
1 <= |A| <= 20

Input Format:
Given a character array A.

Output Format:
Return an integer.

Example Input:
Input 1:
A = ['S', 'c', 'a', 'l', 'e', 'r', '@', '1']
Input 2:
A = ['I', 'n', 't', 'e', 'r', 'v', 'i', 'e', 'w', 'B', 'i', 't']

Example Output:
Output 1:
1
Output 2:
0

Example Explanation:
Explanation 1:
All the characteristic required for password are present in given password.
Explanation 2:
The password given does not have any special character and also it does not have any numerical digit.
*/


// Time Complexity = O(n), Space Complexity = O(1)
int Solution::solve(string A) {    
    int flag1 = 0;
    int flag2 = 0;
    int flag3 = 0;
    int flag4 = 0;
    int flag5 = 0;
    
    if(A.length()>=8 && A.length()<=15) 
        flag2 = 1;
        
    for(int i=0; i<A.length(); i++) {
        if(A[i]>='0' && A[i]<='9') 
            flag1 = 1;
        if((A[i])>='a' && (A[i])<='z') 
            flag3 = 1;
        if((A[i])>='A' && (A[i])<='Z') 
            flag4 = 1;
        if(A[i]=='@' || A[i]=='#' || A[i]=='%' || A[i]=='&' || A[i]=='!' || A[i]=='$' || A[i]=='*') 
            flag5 = 1;
    }
    
    if(flag1 == 1 && flag2 == 1 && flag3 == 1 && flag4 == 1 && flag5 == 1) 
        return 1;
    else 
        return 0;
}

