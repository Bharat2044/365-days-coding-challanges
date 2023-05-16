// Question Link: https://leetcode.com/problems/valid-parentheses/

/*
20. Valid Parentheses:

Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

An input string is valid if:
Open brackets must be closed by the same type of brackets.
Open brackets must be closed in the correct order.
Every close bracket has a corresponding open bracket of the same type. 

Example 1:
Input: s = "()"
Output: true
Example 2:
Input: s = "()[]{}"
Output: true
Example 3:
Input: s = "(]"
Output: false 

Constraints:
1 <= s.length <= 104
s consists of parentheses only '()[]{}'.
*/


// Time Complexity = O(n), SPace Complexity = O(n)
class Solution {
public:
    bool isValid(string s) {
        
        stack<char> temp;
        
        for (int i = 0; i < s.length(); i++) {
            if (temp.empty()) 
                temp.push(s[i]);
            
            else if ((temp.top() == '(' && s[i] == ')') || (temp.top() == '{' && s[i] == '}') ||(temp.top() == '[' && s[i] == ']')) 
                temp.pop();
            else 
                temp.push(s[i]);
            
        }
        if (temp.empty()) 
            return true;
        
        return false;
    }
};
