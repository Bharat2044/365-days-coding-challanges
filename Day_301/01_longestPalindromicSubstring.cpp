// Question Link: https://www.interviewbit.com/problems/longest-palindromic-substring/

/*
Longest Palindromic Substring

Problem Description:
Given a string A of size N, find and return the longest palindromic substring in A.
Substring of string A is A[i...j] where 0 <= i <= j < len(A)

Palindrome string:
A string which reads the same backwards. More formally, A is palindrome if reverse(A) = A.
Incase of conflict, return the substring which occurs first ( with the least starting index).

Problem Constraints:
1 <= N <= 6000 

Input Format:
First and only argument is a string A.

Output Format:
Return a string denoting the longest palindromic substring of string A.

Example Input:
A = "aaaabaaa"

Example Output:
"aaabaaa"

Example Explanation:
We can see that longest palindromic substring is of length 7 and the string is "aaabaaa".
*/



void helper(int l,int r,string &s,int &maxlen,int &left,int &right){
    while(l>=0 && r<s.size() && s[l]==s[r]){
        if(r-l+1>maxlen){
            maxlen=r-l+1;
            left=l;
            right=r;
        }
        
        l--;
        r++;
    }
}

string Solution::longestPalindrome(string A) {
    int maxlen=1;
    int left=0,right=0;
    
    for(int i=1;i<A.size();i++){
        helper(i-1,i+1,A,maxlen,left,right);
    }
    
    for(int i=0;i<A.size();i++){
        helper(i,i+1,A,maxlen,left,right);
    }
    
    return A.substr(left,right-left+1);
}
