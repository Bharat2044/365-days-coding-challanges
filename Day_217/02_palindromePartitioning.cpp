// Question Link: https://leetcode.com/problems/palindrome-partitioning/

/*
131. Palindrome Partitioning

Given a string s, partition s such that every substring of the partition is a palindrome. 
Return all possible palindrome partitioning of s.

Example 1:
Input: s = "aab"
Output: [["a","a","b"],["aa","b"]]
Example 2:
Input: s = "a"
Output: [["a"]]
 
Constraints:
1 <= s.length <= 16
s contains only lowercase English letters.
*/


class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ret;
        vector<string> temp;

        partition_help(s, 0, s.length(), temp, ret);
        
        return ret;
    }
    
    void partition_help(string &s, int start, int len, vector<string> temp, vector<vector<string>> &ret)
    {
        if (len <= 0)
        {
            ret.push_back(temp);
            return;
        }
        
        for (int i = 1; i <= len; i++)
        {
            if (palindrome_judge(s, start, start+i-1))
            {
                string ss = s.substr(start, i);
                temp.push_back(ss);
                partition_help(s, start+i, len-i, temp, ret);
                temp.pop_back();
            }
        }
    }
    
    bool palindrome_judge(string &s, int start, int end)
    {
        int mid = start + ((end - start) >> 1);
        
        while (start <= mid)
        {
            if (s[start] != s[end])
                return false;
            start++;
            end--;
        }
        
        return true;
    }
};
