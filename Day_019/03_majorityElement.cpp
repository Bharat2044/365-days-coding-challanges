// Question Link: https://leetcode.com/problems/majority-element/

/*
169. Majority Element:

Given an array nums of size n, return the majority element.
The majority element is the element that appears more than ⌊n / 2⌋ times. You may assume that the majority element always exists in the array.

Example 1:
Input: nums = [3,2,3]
Output: 3
Example 2:
Input: nums = [2,2,1,1,1,2,2]
Output: 2 

Constraints:
n == nums.length
1 <= n <= 5 * 104
-109 <= nums[i] <= 109 

Follow-up: Could you solve the problem in linear time and in O(1) space?
*/


class Solution {
public:
    int majorityElement(vector<int>& nums) {
        
        
        // Approach - 1: Time Complexity = O(n^2), Space Complexity = O(1)
        /*for(int i=0; i<nums.size(); i++) {
            int count = 0;

            for(int j=0; j<nums.size(); j++) {
                if(nums[i] == nums[j])
                    count++;
            }

            if(count > nums.size()/2)
                return nums[i];
        }

        return -1;*/
        
        
        // Approach - 2: Time Complexity = O(n), Space Complexity = O(1)        
        int count = 0;
        int ele;

        for(int i=0; i<nums.size(); i++) {

            if(count == 0) {
                count = 1;
                ele = nums[i];
            }        
            else if(nums[i] == ele)
                count++;
            else
                count--;
        }

        int count1 = 0;

        for(int i=0; i<nums.size(); i++) {        
            if(nums[i] == ele) 
                count1++;
        }

        return (count1 > nums.size()/2) ? ele : -1;
    }
};
