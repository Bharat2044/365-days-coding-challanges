// Question Link: https://www.interviewbit.com/problems/longest-valid-parentheses/

/*
Longest valid Parentheses

Given a string A containing just the characters ’(‘ and ’)’.

Find the length of the longest valid (well-formed) parentheses substring.

Input Format:
The only argument given is string A.

Output Format:
Return the length of the longest valid (well-formed) parentheses substring.

Constraints:
1 <= length(A) <= 750000

For Example:

Input 1:
    A = "(()"
Output 1:
    2
    Explanation 1:
        The longest valid parentheses substring is "()", which has length = 2.

Input 2:
    A = ")()())"
Output 2:
    4
    Explanation 2:
        The longest valid parentheses substring is "()()", which has length = 4.
*/




int Solution::longestValidParentheses(string A) {
    int n= A.size();
    int i=0;
    
    stack<pair<char, int>> st;
    int maxl=0;
    
    while(i<n){
        if(!st.empty() && A[i]==')' && st.top().first == '(') {
            st.pop();
            
            if(!st.empty())
                maxl = max(maxl, i-st.top().second);
            else 
                maxl= max(maxl, i+1);
        }
        else
            st.push({A[i], i});
        
        i++;
    }
    
    return maxl;
}
