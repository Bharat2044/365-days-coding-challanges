// Question Link: https://www.interviewbit.com/problems/regular-expression-match/

/*
Regular Expression Match

Problem Description:
Implement wildcard pattern matching with support for '?' and '*' for strings A and B.
'?' : Matches any single character.
'*' : Matches any sequence of characters (including the empty sequence).
The matching should cover the entire input string (not partial).

Problem Constraints:
1 <= |A|, |B| <= 9e4

Input Format:
The first argument of input contains a string A.
The second argument of input contains a string B.

Output Format:
Return 0 or 1:
=> 0 : If the patterns do not match.
=> 1 : If the patterns match.

Example Input:
Input 1:
 A = "aa"
 B = "a"
Input 2:
 A = "aa"
 B = "aa"
Input 3:
 A = "aaa"
 B = "aa"
Input 4:
 A = "aa"
 B = "*"
Input 5:
 A = "aa"
 B = "a*"
Input 6:
 A = "ab"
 B = "?*"
Input 7:
 A = "aab"
 B = "c*a*b"

Example Output:
Output 1:
0
Output 2:
1
Output 3:
0
Output 4:
1
Output 5:
1
Output 6:
1
Output 7:
0
*/






int Solution::isMatch(const string a, const string b) {
    int n = a.length();
    int m = b.length();
    
    vector<int>prev(m+1, 0);
    vector<int>curr(m+1, 0);
    prev[0] = 1;
   
    int l = 1;
    while(l<=m && b[l-1] == '*') {
        prev[l] = 1;
        l++;
    }
   
    for(int i=1; i<=n; i++) {        
        for(int j=1; j<=m; j++) {
            
            if(a[i-1] == b[j-1] || b[j-1] == '?')
                curr[j] = prev[j-1];           
            else if(b[j-1] == '*')
                curr[j] = prev[j] || curr[j-1];   
            else
                curr[j] = 0;
        }
        
        prev=curr;
    }
    
    return prev[m];
}









