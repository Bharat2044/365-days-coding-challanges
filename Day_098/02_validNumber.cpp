// Question Link: https://leetcode.com/problems/valid-number/

/*
65. Valid Number

A valid number can be split up into these components (in order):

A decimal number or an integer.
(Optional) An 'e' or 'E', followed by an integer.
A decimal number can be split up into these components (in order):

(Optional) A sign character (either '+' or '-').
One of the following formats:
One or more digits, followed by a dot '.'.
One or more digits, followed by a dot '.', followed by one or more digits.
A dot '.', followed by one or more digits.
An integer can be split up into these components (in order):

(Optional) A sign character (either '+' or '-').
One or more digits.
For example, all the following are valid numbers: ["2", "0089", "-0.1", "+3.14", "4.", "-.9", "2e10", "-90E3", "3e+7", "+6e-1", "53.5e93", "-123.456e789"], while the following are not valid numbers: ["abc", "1a", "1e", "e3", "99e2.5", "--6", "-+3", "95a54e53"].

Given a string s, return true if s is a valid number.

Example 1:
Input: s = "0"
Output: true
Example 2:
Input: s = "e"
Output: false
Example 3:
Input: s = "."
Output: false
 
Constraints:
1 <= s.length <= 20
*/




class Solution {
public:
    bool isNumber(string s) {
        int i=0, n=s.size();

        // iterate over sign
        if(s[i]=='+' || s[i]=='-') i++;

        // checking ending condition
        if(i>=n) return false;
        
        bool beforeInt = false;

        // iterating digits
        while(s[i]>='0' && s[i]<='9' && i<n){
            i++;
            beforeInt = true;
        }

        // checking ending condition
        if(i>=n) return true;

        // Passing dot
        bool dot = false;
        if(s[i] == '.') {i++; dot = true;}

        // check dot ending condition
        if(i>=n)
            if(dot==true && beforeInt==false) return false;
            else return true;
        
        // bool afterInt = false;

        // check digit after dot
        if(dot) 
        if(beforeInt) {if((s[i]<'0' || s[i]>'9') && (s[i]!='e' && s[i]!='E') ) return false; }
        else {if(s[i]<'0' || s[i]>'9') return false; }

        // iterate decimals until we reach last indext or e
        while(i<n && s[i]!='e' && s[i]!='E'){
            if(s[i]<'0' || s[i]>'9') return false;
            i++;
        }
        if(!dot)
        if((s[i]=='e' || s[i]=='E') && beforeInt==false) return false;
        // checking ending condition
        if(i>=n) return true;
        
        i++; // next ot e
        
        // iterate sign
        if(s[i]=='+' || s[i]=='-') i++;

        // checking ending condition
        if(i>=n) return false;

        bool lastInt = false;
        // iterate over digits
        while(s[i]>='0' && s[i]<='9' && i<n){
            i++;
            lastInt = true;
        }

        if(!lastInt) return false;

        if(i>=n) return true;
      
        return false;
    }
};
