// Question Link: https://leetcode.com/problems/scramble-string/

/*
87. Scramble String

We can scramble a string s to get a string t using the following algorithm:

If the length of the string is 1, stop.
If the length of the string is > 1, do the following:
Split the string into two non-empty substrings at a random index, i.e., if the string is s, divide it to x and y where s = x + y.
Randomly decide to swap the two substrings or to keep them in the same order. i.e., after this step, s may become s = x + y or s = y + x.
Apply step 1 recursively on each of the two substrings x and y.
Given two strings s1 and s2 of the same length, return true if s2 is a scrambled string of s1, otherwise, return false.

Example 1:
Input: s1 = "great", s2 = "rgeat"
Output: true
Explanation: One possible scenario applied on s1 is:
"great" --> "gr/eat" // divide at random index.
"gr/eat" --> "gr/eat" // random decision is not to swap the two substrings and keep them in order.
"gr/eat" --> "g/r / e/at" // apply the same algorithm recursively on both substrings. divide at random index each of them.
"g/r / e/at" --> "r/g / e/at" // random decision was to swap the first substring and to keep the second substring in the same order.
"r/g / e/at" --> "r/g / e/ a/t" // again apply the algorithm recursively, divide "at" to "a/t".
"r/g / e/ a/t" --> "r/g / e/ a/t" // random decision is to keep both substrings in the same order.
The algorithm stops now, and the result string is "rgeat" which is s2.
As one possible scenario led s1 to be scrambled to s2, we return true.
Example 2:
Input: s1 = "abcde", s2 = "caebd"
Output: false
Example 3:
Input: s1 = "a", s2 = "a"
Output: true
 
Constraints:
s1.length == s2.length
1 <= s1.length <= 30
s1 and s2 consist of lowercase English letters.
*/



class Solution {
public:
    bool solve(string a, string b,unordered_map <string,bool> &mp){
        if(a==b) // Base Condition which are possible
            return true;  
        int n=a.size();
        if(n<=1)
            return false;
	
        string s=a;
        s+=b;
        if(mp.find(s)!=mp.end())
            return mp[s]; //If already present then return the previously calculated bool Value
        bool flag=false;
        for(int i=1;i<=n-1;i++){
            bool c1=(solve(a.substr(0,i),b.substr(n-i,i),mp) && 
                     solve(a.substr(i,n-i),b.substr(0,n-i),mp)); // Considering Swapping
            bool c2=(solve(a.substr(0,i),b.substr(0,i),mp) && 
                     solve(a.substr(i,n-i),b.substr(i,n-i),mp)); // Not considering Swapping
            if(c1 || c2){ // If any of the Condition 1 OR 2 is TRUE return TRUE else return FALSE
                flag=true;
                break;
            }
        }
        return mp[s]=flag; // Storing the value of "s" = a+b  
    }
    
    bool isScramble(string s1, string s2) {
        if(s1==s2)
            return true; //No Need to check
        unordered_map <string,bool> mp; // To store the various string's that are generated
        return solve(s1,s2,mp);
    }
};
