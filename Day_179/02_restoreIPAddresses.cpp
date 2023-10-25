// Question Link: https://leetcode.com/problems/restore-ip-addresses/

/*
93. Restore IP Addresses

A valid IP address consists of exactly four integers separated by single dots. Each integer is between 0 and 255 (inclusive) and cannot have leading zeros.

For example, "0.1.2.201" and "192.168.1.1" are valid IP addresses, but "0.011.255.245", "192.168.1.312" and "192.168@1.1" are invalid IP addresses.
Given a string s containing only digits, return all possible valid IP addresses that can be formed by inserting dots into s. You are not allowed to reorder or remove any digits in s. You may return the valid IP addresses in any order.

Example 1:
Input: s = "25525511135"
Output: ["255.255.11.135","255.255.111.35"]
Example 2:
Input: s = "0000"
Output: ["0.0.0.0"]
Example 3:
Input: s = "101023"
Output: ["1.0.10.23","1.0.102.3","10.1.0.23","10.10.2.3","101.0.2.3"]
 
Constraints:
1 <= s.length <= 20
s consists of digits only.
*/



class Solution {
public:
   vector<string>ans;
    void back(string &s, string temp, int idx, int dig_cnt){
        if(dig_cnt>4) return;

        if(dig_cnt==4 && idx >=s.length()){
            temp.pop_back();
            ans.push_back(temp);
            return;
        }

        for(int i = 1; i<=3 &&idx+i<=s.length(); i++){

            string num = s.substr(idx,i);
            if(num[0]=='0' && i!=1)
                 break;
            else if(stol(num)<=255){
                back(s,temp+s.substr(idx,i)+ ".", idx+i, dig_cnt+1);
            }
        }
    }

    vector<string> restoreIpAddresses(string s){
        back(s,"",0,0);

        return ans;
    }

};
