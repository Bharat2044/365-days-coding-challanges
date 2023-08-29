// Question Link: https://leetcode.com/problems/decode-string/

/*
394. Decode String

Given an encoded string, return its decoded string.

The encoding rule is: k[encoded_string], where the encoded_string inside the square brackets is being repeated exactly k times. Note that k is guaranteed to be a positive integer.

You may assume that the input string is always valid; there are no extra white spaces, square brackets are well-formed, etc. Furthermore, you may assume that the original data does not contain any digits and that digits are only for those repeat numbers, k. For example, there will not be input like 3a or 2[4].

The test cases are generated so that the length of the output will never exceed 105.

Example 1:
Input: s = "3[a]2[bc]"
Output: "aaabcbc"
Example 2:
Input: s = "3[a2[c]]"
Output: "accaccacc"
Example 3:
Input: s = "2[abc]3[cd]ef"
Output: "abcabccdcdcdef"
 
Constraints:
1 <= s.length <= 30
s consists of lowercase English letters, digits, and square brackets '[]'.
s is guaranteed to be a valid input.
All the integers in s are in the range [1, 300].
*/




class Solution {
public:
    string decodeString(string s) {
        stack<string>str;
        stack<int>count;
        string ans="";
        int num=0;
        for (int i=0;i<s.size();i++){
           if (s[i]>='0' && s[i]<='9'){ 
               num=10*num+s[i]-'0';
           }
           else if (s[i]=='[') {//reset
                str.push(ans);
                ans="";
                count.push(num);
                num=0;
           }
           else if(s[i]==']'){ //add the num times to the ans
               string temp=ans;
               ans=str.top();
               str.pop();
               int times=count.top();
               count.pop();
               while (times--){
                   ans+=temp;
               }
           }
           else { // for char 
               ans+=s[i];
           }

        }
        return ans;
    }
};
