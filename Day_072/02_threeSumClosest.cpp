// Question Link: https://leetcode.com/problems/3sum-closest/

/*
16. 3Sum Closest

Given an integer array nums of length n and an integer target, find three integers in nums such that the sum is closest to target.

Return the sum of the three integers.

You may assume that each input would have exactly one solution.

Example 1:
Input: nums = [-1,2,1,-4], target = 1
Output: 2
Explanation: The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).
Example 2:
Input: nums = [0,0,0], target = 1
Output: 0
Explanation: The sum that is closest to the target is 0. (0 + 0 + 0 = 0).
 
Constraints:
3 <= nums.length <= 500
-1000 <= nums[i] <= 1000
-104 <= target <= 104
*/



class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int n = nums.size();
        
        // Step 1: Sort the array in ascending order
        sort(nums.begin(), nums.end());
        
        int diff = INT_MAX; // Initialize the minimum difference to a large value
        int ans; // Variable to store the closest triplet sum
        
        // Step 4: Iterate over each element in the array
        for(int i=0; i<n; i++){
            int j = i+1; // Initialize the left pointer
            int k = n-1; // Initialize the right pointer
            
            // Step 6: Find the closest triplet sum using two pointers
            while(j < k){
                int sum = nums[i] + nums[j] + nums[k]; // Calculate the current triplet sum
                
                // Step 8: Update the minimum difference and the closest sum if the current sum is closer to the target
                if(abs(sum - target) < diff){
                    diff = abs(sum - target);
                    ans = sum;
                }
                // If equal to sum, end function
                if(sum == target) return sum;

                // Step 9: Adjust the pointers based on the value of the current sum
                if(sum < target) {
                    j++; // Increment the left pointer to consider a larger element
                } else {
                    k--; // Decrement the right pointer to consider a smaller element
                }
            }
        }
        
        // Step 11: Return the closest triplet sum
        return ans;
    }
};
