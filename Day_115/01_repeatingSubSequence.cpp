// Question Link: https://www.interviewbit.com/problems/repeating-subsequence/

/*
Repeating Sub-Sequence

Problem Description:
Given a string A, Check if the length of the longest repeating sub-sequence is greater than or equal to 2,
A longest repeating sub-sequence is defined such that,
the two subsequences have the same string character at the same position
any ith character in the two subsequences shouldn’t have the same index in the original string
NOTE: If the Sub-sequence length is greater than or equal to 2 return 1, else return 0.

Problem Constraints:
 1 <= |A| <= 100

Input Format:
The first and only argument of input contains a string A.

Output Format:
Return an integer, 0 or 1:
    => 0 : Length of Repeating subsequence is less than 2
    => 1 : Length of Repeating subsequence is greater than or equal to 2

Example Input:
Input 1:
 A = "abab"
Input 2:
 A = "abba"
 
Example Output:
Output 1:
 1
Output 2:
0
 
Example Explanation:
Explanation 1:
 "ab" is repeated.
Explanation 2:
 There is no repeating subsequence.
*/



int Solution::anytwo(string A) {
    int n=A.size();
    int L[n + 1][n + 1];
    memset(L,0,sizeof(L));    

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {

            if (i == j)
                L[i][j] = max(L[i - 1][j], L[i][j - 1]);
            else {
                if (A[i - 1] == A[j - 1])
                    L[i][j] = L[i - 1][j - 1] + 1;
                else
                    L[i][j] = max(L[i - 1][j], L[i][j - 1]);
            }
        }
    }

    if(L[n][n] >= 2)
        return 1;
    else
        return 0;
}
