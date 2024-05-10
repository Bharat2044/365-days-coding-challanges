// Question Link: https://leetcode.com/problems/contiguous-array/

/*
525. Contiguous Array

Given a binary array nums, return the maximum length of a contiguous subarray with an equal number of 0 and 1.

Example 1:
Input: nums = [0,1]
Output: 2
Explanation: [0, 1] is the longest contiguous subarray with an equal number of 0 and 1.
Example 2:
Input: nums = [0,1,0]
Output: 2
Explanation: [0, 1] (or [1, 0]) is a longest contiguous subarray with equal number of 0 and 1.
 
Constraints:
1 <= nums.length <= 105
nums[i] is either 0 or 1.
*/


class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int n=nums.size(), n1=0, n0=0, len=0;
        unordered_map<int, int> mp;
        mp[0]=-1;
        for(int i=0; i<n; i++){
            n1+=nums[i];
            n0=(i+1)-n1;
            if (mp.count(n1-n0)!=0) 
                len=max(len, i-mp[n1-n0]);
            else 
                mp[n1-n0]=i;
        } 
        return len;  
    }
};
