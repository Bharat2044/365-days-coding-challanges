// Question Link: https://leetcode.com/problems/majority-element-ii/

/*
229. Majority Element II

Given an integer array of size n, find all elements that appear more than ⌊ n/3 ⌋ times.

Example 1:
Input: nums = [3,2,3]
Output: [3]
Example 2:
Input: nums = [1]
Output: [1]
Example 3:
Input: nums = [1,2]
Output: [1,2]
 
Constraints:
1 <= nums.length <= 5 * 104
-109 <= nums[i] <= 109
 
Follow up: Could you solve the problem in linear time and in O(1) space?
*/



class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
       vector<int> result;
        if (nums.empty()) {
            return result;
        }
        
        int p1 = 0, p2 = 0;
        int count1 = 0, count2 = 0;
        
        for (int num : nums) {
            if (num == p1) {
                count1++;
            } else if (num == p2) {
                count2++;
            } else if (count1 == 0) {
                p1 = num;
                count1 = 1;
            } else if (count2 == 0) {
                p2 = num;
                count2 = 1;
            } else {
                count1--;
                count2--;
            }
        }
        
        count1 = 0;
        count2 = 0;
        for (int num : nums) {
            if (num == p1) {
                count1++;
            } else if (num == p2) {
                count2++;
            }
        }
        
        int n = nums.size();
        if (count1 * 3 > n) {
            result.push_back(p1);
        }
        if (count2 * 3 > n) {
            result.push_back(p2);
        }
        
        return result;
    }
};
