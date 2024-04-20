// Question Link: https://www.interviewbit.com/problems/minimum-characters-required-to-make-a-string-palindromic/

/*
Minimum Characters required to make a String Palindromic

Problem Description:
Given a string A. The only operation allowed is to insert characters at the beginning of the string.
Find how many minimum characters are needed to be inserted to make the string a palindrome string.

Problem Constraints:
1 <= |A| <= 10^6

Input Format:
The only argument given is string A.

Output Format:
Return the minimum characters that are needed to be inserted to make the string a palindrome string.

Example Input:
Input 1:
A = "ABC"
Input 2:
A = "AACECAAAA"

Example Output:
Output 1:
2
Output 2:
2

Example Explanation:
Explanation 1:
Insert 'B' at beginning, string becomes: "BABC".
Insert 'C' at beginning, string becomes: "CBABC".
Explanation 2:
Insert 'A' at beginning, string becomes: "AAACECAAAA".
Insert 'A' at beginning, string becomes: "AAAACECAAAA".
*/



int lps(string pat){
    int M = pat.size();
    int lps[M];
    
    int len = 0;
    int i = 1;
    lps[0] = 0;

    while(i < M){
        if(pat[i] == pat[len]){
            len++;
            lps[i] = len;
            i++;
        }else{

            if(len!=0){
                len = lps[len-1];
            } else{
                lps[i] = 0;
                i++;
            }
        }
    }

    return lps[M-1];
}

int Solution::solve(string A) {
    string B = A;
    reverse(B.begin(), B.end());

    string pat = A+"$"+B;
    int len = lps(pat);
    
    return A.size() - len;
}
