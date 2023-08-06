// Question Link: https://leetcode.com/problems/add-binary/

/*
67. Add Binary

Given two binary strings a and b, return their sum as a binary string.

Example 1:
Input: a = "11", b = "1"
Output: "100"
Example 2:
Input: a = "1010", b = "1011"
Output: "10101"
 
Constraints:
1 <= a.length, b.length <= 104
a and b consist only of '0' or '1' characters.
Each string does not contain leading zeros except for the zero itself.
*/




class Solution {
public:
    string addBinary(string a, string b) {
        string ans = "";
        int s1 = a.size()-1;
        int s2 = b.size()-1;
        int carry = 0;
        while(s1>=0 || s2>=0 || carry==1){
            carry += s1>=0 ? a[s1--]-'0' : 0;
            carry += s2>=0 ? b[s2--]-'0' : 0;
            ans = (char)(carry%2+'0')+ans;
            carry /= 2;
        }
        return ans;

        // long long n1 = stoi(a);
        // long long n2 = stoi(b);
        // int carry = 0;
        // long long ans = 0, power = 1;
        // while(n1>0 || n2>0 || carry>0){
        //     int d1 = n1%10;
        //     int d2 = n2%10;
        //     n1 /= 10;
        //     n2 /= 10;
        //     int digit = 0;
        //     if(d1+d2+carry >= 2) {
        //         digit = (d1+d2+carry)%2;
        //         carry = (d1+d2+carry)/2;
        //     }
        //     else {
        //         digit = d1+d2+carry;
        //         carry = 0;
        //     }
        //     ans += digit*power;
        //     power *= 10;
        // }
        // return to_string(ans);
        
    }
};
