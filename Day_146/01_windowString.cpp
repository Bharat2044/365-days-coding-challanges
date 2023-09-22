// Question Link: https://www.interviewbit.com/problems/window-string/

/*
Window String

Problem Description:
Given a string A and a string B, find the window with minimum length in A, which will contain all the characters in B in linear time complexity.
 Note that when the count of a character c in B is x, then the count of c in the minimum window in A should be at least x.

Note:
If there is no such window in A that covers all characters in B, return the empty string.
If there are multiple such windows, return the first occurring minimum window ( with minimum start index and length )
 
Problem Constraints:
1 <= size(A), size(B) <= 106

Input Format:
The first argument is a string A.
The second argument is a string B.

Output Format:
Return a string denoting the minimum window.

Example Input:
Input 1:
 A = "ADOBECODEBANC"
 B = "ABC"
Input 2:
 A = "Aa91b"
 B = "ab"
 
Example Output:
Output 1:
 "BANC"
Output 2:
 "a91b"

Example Explanation:
Explanation 1:
 "BANC" is a substring of A which contains all characters of B.
Explanation 2:
 "a91b" is the substring of A which contains all characters of B.
*/




string Solution::minWindow(string s, string p) {
 
    int hash_s[256]={0};
       int hash_p[256]={0};
       if(s.length()<p.length())return "";
       
       for(int i=0;i<p.length();i++)
       hash_p[p[i]]++;
       
       int start=0;
       int min_len=INT_MAX; 
       int start_index=-1;
       int count=0;
       
       for(int i=0;i<s.length();i++){
           hash_s[s[i]]++;
           
           if(hash_s[s[i]]<=hash_p[s[i]])
           count++;
           
        
        if(count==p.length()){   
            while(hash_s[s[start]]>hash_p[s[start]] || hash_p[s[start]]==0){
               if(hash_s[s[start]]>hash_p[s[start]])
               hash_s[s[start]]--;
               
               start++;
           }
          int len=i-start+1;
          if(min_len>len){
            min_len=len;
            start_index=start;}
       
        } 
    }

    if(start_index==-1)
    return "";
    else
    return s.substr(start_index,min_len);
}
