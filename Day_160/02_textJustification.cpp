// Question Link: https://leetcode.com/problems/text-justification/

/*
68. Text Justification

Given an array of strings words and a width maxWidth, format the text such that each line has exactly maxWidth characters and is fully (left and right) justified.

You should pack your words in a greedy approach; that is, pack as many words as you can in each line. Pad extra spaces ' ' when necessary so that each line has exactly maxWidth characters.

Extra spaces between words should be distributed as evenly as possible. If the number of spaces on a line does not divide evenly between words, the empty slots on the left will be assigned more spaces than the slots on the right.

For the last line of text, it should be left-justified, and no extra space is inserted between words.

Note:
A word is defined as a character sequence consisting of non-space characters only.
Each word's length is guaranteed to be greater than 0 and not exceed maxWidth.
The input array words contains at least one word.
 
Example 1:
Input: words = ["This", "is", "an", "example", "of", "text", "justification."], maxWidth = 16
Output:
[
   "This    is    an",
   "example  of text",
   "justification.  "
]
Example 2:
Input: words = ["What","must","be","acknowledgment","shall","be"], maxWidth = 16
Output:
[
  "What   must   be",
  "acknowledgment  ",
  "shall be        "
]
Explanation: Note that the last line is "shall be    " instead of "shall     be", because the last line must be left-justified instead of fully-justified.
Note that the second line is also left-justified because it contains only one word.
Example 3:
Input: words = ["Science","is","what","we","understand","well","enough","to","explain","to","a","computer.","Art","is","everything","else","we","do"], maxWidth = 20
Output:
[
  "Science  is  what we",
  "understand      well",
  "enough to explain to",
  "a  computer.  Art is",
  "everything  else  we",
  "do                  "
]
 
Constraints:
1 <= words.length <= 300
1 <= words[i].length <= 20
words[i] consists of only English letters and symbols.
1 <= maxWidth <= 100
words[i].length <= maxWidth
*/




class Solution {
public:
    vector<string> ans;

    string space(int c) {
        return string(c, ' ');
    }

    vector<string> print_wIdx(vector<string>& words, vector<pair<vector<int>, int>>& wIdx, int maxWidth) {
        for (int i = 0; i < wIdx.size(); i++) {
            int numWords = wIdx[i].first.size();
            int totalLen = wIdx[i].second;
            int totalSpaces = maxWidth - totalLen;
            int numGaps = numWords - 1;
            int numSpaces = 1;
            int remainingSpaces = 0;

            if (numGaps > 0) {
                numSpaces = totalSpaces / numGaps;
                remainingSpaces = totalSpaces % numGaps;
            }

            string line = words[wIdx[i].first[0]]; // Start with the first word
            for (int j = 1; j < numWords; j++) {
                if (i == wIdx.size() - 1) {
                    // Last line, left justify
                    line += space(1);
                } 
                else {
                    line+= space(numSpaces+(remainingSpaces>0?1:0));
                    remainingSpaces--;
                }
                line+= words[wIdx[i].first[j]];
            }

            if (line.size() < maxWidth)
                line+= space(maxWidth-line.size());

            ans.push_back(line);
        }

        return ans;
    }

    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        int n = words.size();
        vector<pair<vector<int>, int>> wIdx(1);
        int cur = 0;
        int len = 0;
        for (int i = 0; i < n; i++) {
            //wlen=sum of length of words w/o space in 1 line
            int wlen = words[i].size();
            len += wlen;
            if (len > maxWidth) {
                wIdx.push_back({{i}, wlen});
                cur++;
                len = wlen;
            } 
            else {
                wIdx[cur].first.push_back(i);
                wIdx[cur].second += wlen;
            }
            len++; //at least 1 whitespace between words
        }

        return print_wIdx(words, wIdx, maxWidth);
    }
};
