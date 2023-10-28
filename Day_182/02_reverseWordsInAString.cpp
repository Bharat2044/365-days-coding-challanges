// Question Link: https://leetcode.com/problems/reverse-words-in-a-string/

/*
151. Reverse Words in a String

Given an input string s, reverse the order of the words.

A word is defined as a sequence of non-space characters. The words in s will be separated by at least one space.

Return a string of the words in reverse order concatenated by a single space.

Note that s may contain leading or trailing spaces or multiple spaces between two words. The returned string should only have a single space separating the words. Do not include any extra spaces.

Example 1:
Input: s = "the sky is blue"
Output: "blue is sky the"
Example 2:
Input: s = "  hello world  "
Output: "world hello"
Explanation: Your reversed string should not contain leading or trailing spaces.
Example 3:
Input: s = "a good   example"
Output: "example good a"
Explanation: You need to reduce multiple spaces between two words to a single space in the reversed string.
 
Constraints:
1 <= s.length <= 104
s contains English letters (upper-case and lower-case), digits, and spaces ' '.
There is at least one word in s.
 
Follow-up: If the string data type is mutable in your language, can you solve it in-place with O(1) extra space?
*/



class Solution {
public:
    string reverseWords(string s) {
        // Trim the input string to remove leading and trailing spaces
        int i = 0, j = s.size() - 1;
        while (i <= j && s[i] == ' ') i++;   // Find the first non-space character
        while (j >= i && s[j] == ' ') j--;   // Find the last non-space character
        s = s.substr(i, j - i + 1);          // Extract the trimmed substring

        // Split the trimmed string into words based on spaces
        vector<string> words;                // Create a vector to store words
        stringstream ss(s);                  // Create a stringstream with the trimmed string
        string word;
        while (ss >> word) {                 // Tokenize the string into words
            words.push_back(word);           // Store each word in the vector
        }

        // Initialize the output string
        string out = "";

        // Iterate through the words in reverse order
        for (int i = words.size() - 1; i > 0; i--) {
            // Append the current word and a space to the output
            out += words[i] + " ";
        }

        // Append the first word to the output (without trailing space)
        return out + words[0];               // Concatenate the reversed words
    }
};
