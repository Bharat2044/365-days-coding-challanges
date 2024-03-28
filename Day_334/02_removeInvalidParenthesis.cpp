// Question Link: https://leetcode.com/problems/remove-invalid-parentheses/description/

/*
301. Remove Invalid Parentheses

Given a string s that contains parentheses and letters, remove the minimum number of invalid parentheses to make the input string valid.
Return a list of unique strings that are valid with the minimum number of removals. You may return the answer in any order.

Example 1:
Input: s = "()())()"
Output: ["(())()","()()()"]
Example 2:
Input: s = "(a)())()"
Output: ["(a())()","(a)()()"]
Example 3:
Input: s = ")("
Output: [""]
 
Constraints:
1 <= s.length <= 25
s consists of lowercase English letters and parentheses '(' and ')'.
There will be at most 20 parentheses in s.
*/



class Solution {
private:
unordered_map<string,int> dp;
int Remove_Invalid_Parentheses(string s,int cnt,set<string>& st){
    if(cnt==0){
        int minr = solve(s);
        if(minr==0){
            st.insert(s);
            return 1;
        }
        return 0;
    }
    if(dp.find(s)!=dp.end())return dp[s];
    for(int i=0;i<s.size();i++){
        if(s[i]==')'||s[i]=='('){
            string left = s.substr(0,i);
            string right = s.substr(i+1);
            dp[left+right] = Remove_Invalid_Parentheses(left+right,cnt-1,st);
        }
    }
    return dp[s];
}
int solve(string s){
    int cnt = 0,n=s.size();
    stack<char> st;
    for(int i=0;i<n;i++){
        if(s[i]=='('){
            st.push('(');
        }else if(s[i]==')') {
            if(!st.empty()&&st.top()=='(')st.pop();
            else st.push(s[i]);
        }
    }
    return st.size();
}

public:
    vector<string> removeInvalidParentheses(string s) {
        vector<string> v;
        int cnt = solve(s);
        set<string> st;
        Remove_Invalid_Parentheses(s,cnt,st);
        while(!st.empty()){
            v.push_back(*st.begin());
            st.erase(st.begin());
        }
        cout<<cnt<<endl;
        return v;
    }
};
