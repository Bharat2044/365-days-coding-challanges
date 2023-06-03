// Question Link: https://leetcode.com/problems/find-the-index-of-the-first-occurrence-in-a-string/

/*
28. Find the Index of the First Occurrence in a String:

Given two strings needle and haystack, return the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.

Example 1:
Input: haystack = "sadbutsad", needle = "sad"
Output: 0
Explanation: "sad" occurs at index 0 and 6.
The first occurrence is at index 0, so we return 0.
Example 2:
Input: haystack = "leetcode", needle = "leeto"
Output: -1
Explanation: "leeto" did not occur in "leetcode", so we return -1. 

Constraints:
1 <= haystack.length, needle.length <= 104
haystack and needle consist of only lowercase English characters.
*/



class Solution {
public:
    int strStr(string haystack, string needle) {
        
        // if (haystack.find(needle) != string::npos) 
        //     return haystack.find(needle);        
        // else 
        //     return -1;
        
        
        
        int n = haystack.length();
        int m = needle.length();

        for(int i=0; i<n; i++){
            int j;
            
            for(j=0 ; j<m ; j++){
                if(haystack[i+j] != needle[j])
                    break;
            }
            if(j == m)
                return i;
        }
        
        return -1;
    }
};
