// Question Link: https://leetcode.com/problems/strange-printer/

/*
664. Strange Printer

There is a strange printer with the following two special properties:

The printer can only print a sequence of the same character each time.
At each turn, the printer can print new characters starting from and ending at any place and will cover the original existing characters.
Given a string s, return the minimum number of turns the printer needed to print it.

Example 1:
Input: s = "aaabbb"
Output: 2
Explanation: Print "aaa" first and then print "bbb".
Example 2:
Input: s = "aba"
Output: 2
Explanation: Print "aaa" first and then print "b" from the second place of the string, which will cover the existing character 'a'.

Constraints:
1 <= s.length <= 100
s consists of lowercase English letters.
*/


class Solution {
public:
    int strangePrinter(string s) {
        std::unordered_map<std::string, int> memo;
        return min_turns_to_print(0, s.length() - 1, s, memo);        
    }

private:
    int min_turns_to_print(int start, int end, const std::string& s, std::unordered_map<std::string, int>& memo) {
        if (start > end) {
            return 0;
        }
        
        std::string key = std::to_string(start) + "-" + std::to_string(end);
        if (memo.count(key)) {
            return memo[key];
        }
        
        int res = min_turns_to_print(start, end - 1, s, memo) + 1;

        for (int middle = start; middle < end; middle++) {
            if (s[middle] == s[end]) {
                res = std::min(res, min_turns_to_print(start, middle, s, memo) + min_turns_to_print(middle + 1, end - 1, s, memo));
            }
        }
        
        memo[key] = res;
        return res;
    }    
};
