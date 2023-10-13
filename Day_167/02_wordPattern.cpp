// Question Link: https://leetcode.com/problems/word-pattern/

/*
290. Word Pattern

Given a pattern and a string s, find if s follows the same pattern.

Here follow means a full match, such that there is a bijection between a letter in pattern and a non-empty word in s.

Example 1:
Input: pattern = "abba", s = "dog cat cat dog"
Output: true
Example 2:
Input: pattern = "abba", s = "dog cat cat fish"
Output: false
Example 3:
Input: pattern = "aaaa", s = "dog cat cat dog"
Output: false
 
Constraints:
1 <= pattern.length <= 300
pattern contains only lower-case English letters.
1 <= s.length <= 3000
s contains only lowercase English letters and spaces ' '.
s does not contain any leading or trailing spaces.
All the words in s are separated by a single space.
*/



class Solution {
   
public:
    bool wordPattern(string pattern, string s) {
        unordered_map<char,string>mp;
        unordered_map<string,char>mp2;
        int j =0;
        int i =0;
        while( i<pattern.length() && j<s.length()){
         string str = "";

        while(j<s.length() && s[j]!=' '){
          str+=s[j];
          j++;
        }
        j++;
        if(mp.count(pattern[i]))
             if(mp[pattern[i]]!=str)return false;
         if(mp2.count(str))
          if(mp2[str]!=pattern[i])return false;
         //else 
             mp[pattern[i]]=str;
             mp2[str]=pattern[i];
         i++;
      }
      if(j<s.length())return false;
       if(i<pattern.length())return false;
       
      return true;
    }
};
