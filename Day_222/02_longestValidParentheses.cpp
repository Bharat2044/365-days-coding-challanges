// Question Link: https://leetcode.com/problems/longest-valid-parentheses/

/*
32. Longest Valid Parentheses

Given a string containing just the characters '(' and ')', return the length of the longest valid (well-formed) parentheses substring.

Example 1:
Input: s = "(()"
Output: 2
Explanation: The longest valid parentheses substring is "()".
Example 2:
Input: s = ")()())"
Output: 4
Explanation: The longest valid parentheses substring is "()()".
Example 3:
Input: s = ""
Output: 0

Constraints:
0 <= s.length <= 3 * 104
s[i] is '(', or ')'.
*/


class Solution {
public:
    int longestValidParentheses(string s) {
        int n = s.length();
        
        stack<int>st;
        int trash = 0;
        int ans = 0;
        for(int i=1; i<=n; i++){
            if(s[i-1]=='('){
                st.push(i);
            }
            else{
                if(st.empty()){
                    trash= i;
                    continue;
                }
                else{
                    st.pop();
                }
                if(st.empty()){
                    ans= max(ans, (int)(i-trash));
                }
                else{
                    ans= max(ans, (int)(i-st.top()));
                } 
            }
            
        }
        return ans;
    }
};
