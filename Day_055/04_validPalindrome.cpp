// Question Link: https://leetcode.com/problems/valid-palindrome/description/

/*
125. Valid Palindrome

A phrase is a palindrome if, after converting all uppercase letters into lowercase letters and removing all non-alphanumeric characters, it reads the same forward and backward. Alphanumeric characters include letters and numbers.

Given a string s, return true if it is a palindrome, or false otherwise.

Example 1:
Input: s = "A man, a plan, a canal: Panama"
Output: true
Explanation: "amanaplanacanalpanama" is a palindrome.
Example 2:
Input: s = "race a car"
Output: false
Explanation: "raceacar" is not a palindrome.
Example 3:
Input: s = " "
Output: true
Explanation: s is an empty string "" after removing non-alphanumeric characters.
Since an empty string reads the same forward and backward, it is a palindrome.
 
Constraints:
1 <= s.length <= 2 * 105
s consists only of printable ASCII characters.
*/



// Time Complexity = O(n), Space Complexity = O(1)
class Solution {
public:
    bool isPalindrome(string s) {
        int low = 0;
        int high = s.size()-1;
            
        while(low < high){
            while((low < high) && !isalnum(s[low]))
                low++; 
            
            while((low < high) && !isalnum(s[high]))
                high--;

            if(tolower(s[low++]) != tolower(s[high--]))
                return false;
        }
            
        return true;
    }
};
