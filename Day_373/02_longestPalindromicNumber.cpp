// Question Link: https://leetcode.com/problems/largest-palindromic-number/description/

/*
2384. Largest Palindromic Number

You are given a string num consisting of digits only.
Return the largest palindromic integer (in the form of a string) that can be formed using digits taken from num. It should not contain leading zeroes.

Notes:
You do not need to use all the digits of num, but you must use at least one digit.
The digits can be reordered.
 
Example 1:
Input: num = "444947137"
Output: "7449447"
Explanation: 
Use the digits "4449477" from "444947137" to form the palindromic integer "7449447".
It can be shown that "7449447" is the largest palindromic integer that can be formed.
Example 2:
Input: num = "00009"
Output: "9"
Explanation: 
It can be shown that "9" is the largest palindromic integer that can be formed.
Note that the integer returned should not contain leading zeroes.
 
Constraints:
1 <= num.length <= 10^5
num consists of digits.
*/



class Solution {
public:
    string largestPalindromic(string num) {
        map<char,int> mp;
        priority_queue<char> pq;
        int n= num.length();
        for(int i=0;i<n;i++){
            mp[num[i]]++;
            
        }
        for(auto it:mp){
            pq.push(it.first);
        }
        string res="";
        vector<char> v;
        while(!pq.empty()){
            char c = pq.top();
            pq.pop();
            int freq = mp[c];
            if(freq>=2){
                if(freq%2!=0){
                    v.push_back(c);
                }
                freq/=2;
                while(freq>0){
                    res += string(1,c);
                    freq--;
                }
            }
            else{
                v.push_back(c);
            }
            
            
        }
        sort(v.begin(), v.end());
        string t = res;
        reverse(res.begin(), res.end());
        res = t + (v.empty() ? "" : string(1, v.back())) + res;

        // Remove leading zeros
        int i = 0;
        while (i < res.length() && res[i] == '0') {
            i++;
        }
        return i == res.length() ? "0" : res.substr(i,res.length()-2*i);
    }
};
