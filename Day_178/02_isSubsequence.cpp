// Question Link: https://leetcode.com/problems/is-subsequence/

/*
392. Is Subsequence

Given two strings s and t, return true if s is a subsequence of t, or false otherwise.

A subsequence of a string is a new string that is formed from the original string by deleting some (can be none) of the characters without disturbing the relative positions of the remaining characters. (i.e., "ace" is a subsequence of "abcde" while "aec" is not).

Example 1:
Input: s = "abc", t = "ahbgdc"
Output: true
Example 2:
Input: s = "axc", t = "ahbgdc"
Output: false
 
Constraints:
0 <= s.length <= 100
0 <= t.length <= 104
s and t consist only of lowercase English letters.
 
Follow up: Suppose there are lots of incoming s, say s1, s2, ..., sk where k >= 109, and you want to check one by one to see if t has its subsequence. In this scenario, how would you change your code?
*/



class Solution {
public:
    bool isSubsequence(string s, string t) {
        int n = s.length(),m=t.length();
        int j = 0; 
        // For index of s (or subsequence
    
        // Traverse s and t, and
        // compare current character
        // of s with first unmatched char
        // of t, if matched
        // then move ahead in s
        for (int i = 0; i < m and j < n; i++)
            if (s[j] == t[i])
                j++;
    
        // If all characters of s were found in t
        return (j == n);
    }
};
