// Question Link: https://leetcode.com/problems/longest-common-prefix/

/*
14. Longest Common Prefix

Write a function to find the longest common prefix string amongst an array of strings.

If there is no common prefix, return an empty string "".

Example 1:
Input: strs = ["flower","flow","flight"]
Output: "fl"
Example 2:
Input: strs = ["dog","racecar","car"]
Output: ""
Explanation: There is no common prefix among the input strings.
 
Constraints:
1 <= strs.length <= 200
0 <= strs[i].length <= 200
strs[i] consists of only lowercase English letters.
*/



class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        sort(strs.begin(), strs.end());

        int a = strs.size();
        string n = strs[0], m = strs[a-1], ans = "";

        for(int i=0; i<n.size(); i++){
            if(n[i] == m[i])
                ans += n[i];
            else 
                break;
        }

        return ans;        
    }
};

