// Question Link: https://www.interviewbit.com/problems/text-editor/

/*
Text Editor

Problem Description:
Michael is working on a very basic text editor. Initially, nothing is written on the editor. Also, the editor stores a buffer which is initially empty. In one operation, Michael can do one of the following operations-
1. Append any lowercase English character to the current string on the editor. After this operation, the buffer becomes empty (if anything was stored in the buffer previously).
2. Copy the current string on the editor to the buffer. Note that the complete string gets copied. You can't copy strings partially. Any previously stored string in the buffer is replaced.
3. Append the string in the buffer to the current string. Note that after this operation, the buffer is still intact.

You are given a string A. Help Michael find the minimum number of operations required to write the string A on the editor.

Problem Constraints:
1 <= |A| <= 5 x 10^5

Input Format:
The first and only argument contains the string A.

Output Format:
Return an integer, the minimum number of operations required to write the string A on the text editor.

Example Input:
Input 1:
  A : "abababababab"
Input 2:
  A : "aaaabaaaab"
  
Example Output:
Output 1:
  7
Output 2:
  7

Example Explanation:
Explanation 1:
  One of the ways to write this string in 7 operations is-
  1. Append 'a' to the editor. Current string = "a", Current Buffer = "" 
  2. Append 'b' to the editor. Current string = "ab", Current Buffer = ""
  3. Copy the string to buffer. Current string = "ab", Current Buffer = "ab"
  4. Append the string in buffer to current string. Current string = "abab", Current Buffer = "ab"
  5. Append the string in buffer to current string. Current string = "ababab", Current Buffer = "ab"
  6. Copy the string to buffer. Current string = "ababab", Current Buffer = "ababab"
  7. Append the string in buffer to current string. Current string = "abababababab", Current Buffer = "ababab"
Explanation 2:
  One of the ways to write this string in 7 operations is-
  1. Append 'a' to the editor. Current string = "a", Current Buffer = "" 
  2. Append 'a' to the editor. Current string = "aa", Current Buffer = "" 
  3. Copy the string to buffer. Current string = "aa", Current Buffer = "aa"
  4. Append the string in buffer to current string. Current string = "aaaa", Current Buffer = "aa"
  5. Append 'b' to the editor. Current string = "aaaab", Current Buffer = "" 
  6. Copy the string to buffer. Current string = "aaaab", Current Buffer = "aaaab"
  7. Append the string in buffer to current string. Current string = "aaaabaaaab", Current Buffer = "aaaab"
*/



const int N = 500005;
vector<int>f[N];
int ans[N];
void sieve(){
    if(f[1].size())
        return;
    for(int i = 1; i < N; i++){
        for(int j = i; j < N; j += i)
            f[j].push_back(i);
    }
}
vector<int> prefix_function(string s) {
    int n = (int)s.length();
    vector<int> pi(n);
    for (int i = 1; i < n; i++) {
        int j = pi[i-1];
        while (j > 0 && s[i] != s[j])
            j = pi[j-1];
        if (s[i] == s[j])
            j++;
        pi[i] = j;
    }
    return pi;
}
int Solution::solve(string A) {
    sieve();
    string s = A;
    assert(s.size()>=1 && s.size()<=500000);
    for(char a:A)assert(a>='a' && a<='z');
    vector<int> pi = prefix_function(s);
    ans[0] = 1;
    for(int i = 1; i < s.size(); i++){
        ans[i] = 1 + ans[i-1];
        int k = i+1 - pi[i];
        if((i+1) % k)
            k = i+1;
        int c = (i+1)/k;
        for(auto j : f[c]){
            if(j == c) break;
            ans[i] = min(ans[i], ans[k*j-1] + c/j);
        }
    }
    return ans[s.size()-1];
}
