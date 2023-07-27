// Question Link: https://leetcode.com/problems/add-strings/

/*
415. Add Strings

Given two non-negative integers, num1 and num2 represented as string, return the sum of num1 and num2 as a string.

You must solve the problem without using any built-in library for handling large integers (such as BigInteger). You must also not convert the inputs to integers directly.

Example 1:
Input: num1 = "11", num2 = "123"
Output: "134"
Example 2:
Input: num1 = "456", num2 = "77"
Output: "533"
Example 3:
Input: num1 = "0", num2 = "0"
Output: "0"
 
Constraints:
1 <= num1.length, num2.length <= 104
num1 and num2 consist of only digits.
num1 and num2 don't have any leading zeros except for the zero itself.
*/



class Solution {
public:
    string addStrings(string num1, string num2) {
        int m = num1.size() , n = num2.size();
            int x = abs(m-n);
            string t = "";
      if(x!=0)
      {
        for(int i = 1; i<=x ;i++)
        {
          t+='0';
        }
        if(n>m) num1 = t+num1;
        else{
            num2 = t+num2;
        }
      }
      vector<int> res(num1.size()+1,0);
      int k = res.size()-1;
      for(int i = num1.size()-1 ; i>=0 ; i--)
      { 
        int val = (num1[i]-'0')+(num2[i]-'0')+res[k];
        if(val>=10)
        {
            int t = val-10;
            res[k] = t;
            k--;
            res[k]+=1;
        }
        else{
            res[k] = val;
            k--;
        }
      }
      
    int i = 0;
    string ans = "";
      
    if(res[k]==0 && res[k+1]==0) 
      return "0";
    while(res[i]==0) 
      i++;
      
    for( ;i<res.size();i++)
        ans+=to_string(res[i]);
      
    return ans;
}
};
