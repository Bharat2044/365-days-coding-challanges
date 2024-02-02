// Question Link: https://leetcode.com/problems/reorganize-string/description/

/*
767. Reorganize String

Given a string s, rearrange the characters of s so that any two adjacent characters are not the same.

Return any possible rearrangement of s or return "" if not possible.

Example 1:
Input: s = "aab"
Output: "aba"
Example 2:
Input: s = "aaab"
Output: ""
 
Constraints:
1 <= s.length <= 500
s consists of lowercase English letters.
*/


class Solution {
public:
    string reorganizeString(string s) {
        int hash[26] = {0};
        for(int i = 0; i<s.size();i++) {
            hash[s[i] - 'a']++;
        }
        char max_freq;
        int maxi = INT_MIN;
        for(int i = 0; i < 26;i++) {
            if(hash[i] > maxi) {
                maxi = hash[i];
                max_freq = i + 'a';
            }
        }

        int index = 0;
        while(maxi > 0 && index < s.size()) {
            s[index] = max_freq;
            maxi--;
            index += 2;
        }
        if(maxi != 0) {
            return "";
        }
        // till now we have handle the case for max frequency character
        // now lets do for other
        hash[max_freq - 'a'] = 0;

        for(int i = 0; i<26;i++) {
            while(hash[i] > 0) {
            index = index >= s.size() ? 1 : index;
            s[index] = i + 'a';
            hash[i]--;
            index += 2;
            }
        }
        return s;
    }
};
