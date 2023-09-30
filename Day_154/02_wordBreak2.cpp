// Question Link: https://leetcode.com/problems/word-break-ii/

/*
140. Word Break II

Given a string s and a dictionary of strings wordDict, add spaces in s to construct a sentence where each word is a valid dictionary word. Return all such possible sentences in any order.

Note that the same word in the dictionary may be reused multiple times in the segmentation.

Example 1:
Input: s = "catsanddog", wordDict = ["cat","cats","and","sand","dog"]
Output: ["cats and dog","cat sand dog"]
Example 2:
Input: s = "pineapplepenapple", wordDict = ["apple","pen","applepen","pine","pineapple"]
Output: ["pine apple pen apple","pineapple pen apple","pine applepen apple"]
Explanation: Note that you are allowed to reuse a dictionary word.
Example 3:
Input: s = "catsandog", wordDict = ["cats","dog","sand","and","cat"]
Output: []
 
Constraints:
1 <= s.length <= 20
1 <= wordDict.length <= 1000
1 <= wordDict[i].length <= 10
s and wordDict[i] consist of only lowercase English letters.
All the strings of wordDict are unique.
Input is generated in a way that the length of the answer doesn't exceed 105.
*/



class Solution
{
public:
    vector<string> finalAns;
    void helper(string s, unordered_set<string> &st, int ind, string ans)
    {
        if (ind >= s.length())
        {
            finalAns.push_back(ans); // Reached end of string store the path/words encountered in finalAns.
            return;
        }
        for (int i = ind; i < s.length(); i++)
        {
            string temp = s.substr(ind, i - ind + 1);
            if (st.find(temp) != st.end())
            {
                if (ans.empty()) // First word found no need to add space.
                {
                    helper(s, st, i + 1, ans + temp); 
                }
                else // Other words exist add space.
                {
                    helper(s, st, i + 1, ans + " " + temp); 
                }
            }
        }
        return;
    }
    vector<string> wordBreak(string s, vector<string> &wordDict)
    {
        unordered_set<string> st(wordDict.begin(), wordDict.end());
        helper(s, st, 0, "");
        return finalAns;
    }
};
