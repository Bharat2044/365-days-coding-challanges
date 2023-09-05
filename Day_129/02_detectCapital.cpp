// Question Link: https://leetcode.com/problems/detect-capital/

/*
520. Detect Capital

We define the usage of capitals in a word to be right when one of the following cases holds:

All letters in this word are capitals, like "USA".
All letters in this word are not capitals, like "leetcode".
Only the first letter in this word is capital, like "Google".
Given a string word, return true if the usage of capitals in it is right.

Example 1:
Input: word = "USA"
Output: true
Example 2:
Input: word = "FlaG"
Output: false
 
Constraints:
1 <= word.length <= 100
word consists of lowercase and uppercase English letters.
*/



class Solution {
public:
    bool detectCapitalUse(string word) {
        bool allcapital = false;
        if (isupper(word[0]))
            allcapital = true;
        for(int i=1; i<word.size(); ++i){
            if(islower(word[i]) and allcapital){
                if(i==1) allcapital=false;
                else return false;
            }
            
            if(isupper(word[i]) and !allcapital)
                return false;
        }

        return true;
    }
};
