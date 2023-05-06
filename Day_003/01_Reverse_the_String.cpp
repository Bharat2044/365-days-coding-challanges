// Question Link: https://www.interviewbit.com/problems/reverse-the-string/

/*
Reverse the String:

Problem Description:
You are given a string A of size N.
Return the string A after reversing the string word by word.

NOTE:
A sequence of non-space characters constitutes a word.
Your reversed string should not contain leading or trailing spaces, even if it is present in the input string.
If there are multiple spaces between words, reduce them to a single space in the reversed string.

Problem Constraints:
1 <= N <= 3 * 105

Input Format:
The only argument given is string A.

Output Format:
Return the string A after reversing the string word by word.

Example Input:
Input 1:
    A = "the sky is blue"
Input 2:
    A = "this is ib"

Example Output:
Output 1:
    "blue is sky the"
Output 2:
    "ib is this"
    
Example Explanation:
Explanation 1:
    We reverse the string word by word so the string becomes "the sky is blue".
Explanation 2:
    We reverse the string word by word so the string becomes "this is ib".
    */


// Time Complexity = O(n), Space Complexity = O(n)
string Solution::solve(string A) {
    stack<string> st;
    string str = "";
    
    for(int i=0; i<A.size(); i++) {
        
        if(A[i]== ' ') {
            if(!str.empty())
                st.push(str);
            str = "";
        }
        
        else 
            str += A[i];
    }
    
    st.push(str);    
    string ans = "";
    
    while(!st.empty()){
        if(!ans.empty())
            ans +=' ';
        ans += st.top();
        st.pop();
    }
    
    return ans;
}
