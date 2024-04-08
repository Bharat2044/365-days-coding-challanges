// Question Link: https://leetcode.com/problems/rotate-string/

/*
796. Rotate String

Given two strings s and goal, return true if and only if s can become goal after some number of shifts on s.
A shift on s consists of moving the leftmost character of s to the rightmost position.
For example, if s = "abcde", then it will be "bcdea" after one shift.
 
Example 1:
Input: s = "abcde", goal = "cdeab"
Output: true
Example 2:
Input: s = "abcde", goal = "abced"
Output: false
 
Constraints:
1 <= s.length, goal.length <= 100
s and goal consist of lowercase English letters.
*/



class Solution {
public:
    bool rotateString(string str1, string goal) {
        if(str1.length() != goal.length()) return false;

        string antiClockString = str1;

        int i = 1;
        while(i <= str1.size()){
            i++;
            char temp = antiClockString[0];
            for(int k=0; k<antiClockString.length()-1; k++){
                antiClockString[k] = antiClockString[k+1];
            }
            antiClockString[antiClockString.length()-1] = temp;

            bool antiClockFlag = 0;
            for(int k=0; k<goal.size(); k++){
                if(goal[k] != antiClockString[k]) {
                    antiClockFlag = 1; 
                    break;
                }
            }

            if(!antiClockFlag) return true;
        }
        return false;
    }
};
