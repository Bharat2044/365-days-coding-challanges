// Question Link: https://leetcode.com/problems/buddy-strings/

/*
859. Buddy Strings

Given two strings s and goal, return true if you can swap two letters in s so the result is equal to goal, otherwise, return false.

Swapping letters is defined as taking two indices i and j (0-indexed) such that i != j and swapping the characters at s[i] and s[j].
For example, swapping at indices 0 and 2 in "abcd" results in "cbad".

Example 1:
Input: s = "ab", goal = "ba"
Output: true
Explanation: You can swap s[0] = 'a' and s[1] = 'b' to get "ba", which is equal to goal.
Example 2:
Input: s = "ab", goal = "ab"
Output: false
Explanation: The only letters you can swap are s[0] = 'a' and s[1] = 'b', which results in "ba" != goal.
Example 3:
Input: s = "aa", goal = "aa"
Output: true
Explanation: You can swap s[0] = 'a' and s[1] = 'a' to get "aa", which is equal to goal.
 
Constraints:
1 <= s.length, goal.length <= 2 * 10^4
s and goal consist of lowercase letters.
*/



class Solution {
public:
    bool buddyStrings(string s, string goal) {
        if(s.size()!=goal.size()) return 0;
        int c=0;
        unordered_map<char,int> m;
        char prev1='@',prev2='@';
        int t=0;
        for(int i=0;i<s.size();i++){
            if(s[i]!=goal[i]) t++;
            if(s[i]!=goal[i] && ((goal[i]==prev1 && s[i]==prev2) || prev1=='@')){
                c++;
                prev1=s[i];
                prev2=goal[i];
            } 
            m[s[i]]++;
        }
        int flag=0;
        for(auto i:m){
            if(i.second>1) {flag=1;
            break;
        }
        }
        if((c==2 && t==2) || (t==0 && flag==1)) return 1;
        return 0;
    }
};
