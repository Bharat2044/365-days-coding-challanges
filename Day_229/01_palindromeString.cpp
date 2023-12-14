// Question Link: https://www.interviewbit.com/problems/palindrome-string/

/*
Palindrome String

Problem Description:
Given a string, determine if it is a palindrome. While checking for a palindrome, you have to ignore spaces, case, and all special characters; i.e. consider only alphanumeric characters.

Check the sample test case for reference.
Return 0 / 1 ( 0 for false, 1 for true ) for this problem

Problem Constraints:
1 <= |A| <= 106

Input Format:
The first argument is a string A.

Output Format:
Return 0 / 1 ( 0 for false, 1 for true ) for this problem

Example Input:
Input 1:
"A man, a plan, a canal: Panama"
Input 2:
"race a car"

Example Output:
Output 1:
1
Output 2:
0

Example Explanation:
Explanation 1:
The input string after ignoring spaces, and all special characters is "AmanaplanacanalPanama" 
which is a palindrome after ignoring the case.
Explanation 2:
The input string after ignoring spaces, and all special characters is "raceacar" which is not a palindrome
*/



int Solution::isPalindrome(string A) {
    int n = A.size();
    string B;
    
    if(n==0) 
        return 0;        
    
    for(auto ch:A){
        if(isalnum(ch)) 
            B+=tolower(ch);
    }
    
    int m = B.size();
    int i=0;
    int j=m-1;
    
    while(i<j){
        if(B[i]==B[j]){
            i++;
            j--;
        }
        else{
            return 0;
        }
    }
    
    return 1;
}
