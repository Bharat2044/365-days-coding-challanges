// Question Link: https://www.interviewbit.com/problems/string-inversion/

/*
String Inversion:

Asked In:
Problem Description
Given a string A. Change the cases of all the characters.
If the character is lowercase convert it to uppercase and if the character is uppercase convert it to lowercase.
Note: All the characters in the string are latin uppercase or lowercase letters.

Problem Constraints:
1 <= |A| <= 105

Input Format:
Given a string A.

Output Format:
Return a string.

Example Input:
Input 1:
A = 6 = "InterviewBit"
Input 2:
A = "Scaler"

Example Output:
Output 1:
"iNTERVIEWbIT"
Output 2:
"sCALER"
*/


// Time Complexity = O(n)
string Solution::solve(string A) {
    string ans = "";
    
    for(int i=0; i<A.size(); i++) {
        char ch = A[i];
        
        if((ch >= 'A') && (ch <= 'Z'))
            ans += (char)ch+32;
        else
            ans += (char)ch-32;
    }
    
    return ans;
}
