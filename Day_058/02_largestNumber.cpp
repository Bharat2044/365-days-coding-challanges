// Question Link: https://leetcode.com/problems/largest-number/

/*
179. Largest Number

Given a list of non-negative integers nums, arrange them such that they form the largest number and return it.

Since the result may be very large, so you need to return a string instead of an integer.
 
Example 1:
Input: nums = [10,2]
Output: "210"
Example 2:
Input: nums = [3,30,34,5,9]
Output: "9534330"
 
Constraints:
1 <= nums.length <= 100
0 <= nums[i] <= 109
*/




class Solution {
public:
    static bool comp(string a,string b) {
        return a+b > b+a;
    }
    
    string largestNumber(vector<int>& nums) {
        vector<string> v;

        for(int i=0; i<nums.size(); i++)
            v.push_back(to_string(nums[i]));

        sort(v.begin(), v.end(), comp);

        if(v[0]=="0")
            return "0";

        string an s = "";
        for(string x: v)
            ans += x;

        return ans;
    }
};
