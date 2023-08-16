// Question Link: https://leetcode.com/problems/subsets/

/*
78. Subsets

Given an integer array nums of unique elements, return all possible 
subsets
 (the power set).

The solution set must not contain duplicate subsets. Return the solution in any order.

Example 1:
Input: nums = [1,2,3]
Output: [[],[1],[2],[1,2],[3],[1,3],[2,3],[1,2,3]]
Example 2:
Input: nums = [0]
Output: [[],[0]]

Constraints:
1 <= nums.length <= 10
-10 <= nums[i] <= 10
All the numbers of nums are unique.
*/



class Solution {
public:
    // Recursive helper function to generate subsets of integers
    void helper(vector<vector<int>>& ans, vector<int>& nums, int n, vector<int>& temp, int i) {
        // Base case: if all elements have been considered
        if (n == i) {
            ans.push_back(temp);  // Add the current subset to the answer
            return;
        }
        
        temp.push_back(nums[i]);   // Include the current element in the subset
        helper(ans, nums, n, temp, i + 1);   // Recurse to include next element
        temp.pop_back();            // Backtrack: remove the last added element
        
        helper(ans, nums, n, temp, i + 1);   // Recurse to exclude the current element
    }
    
    // Main function to generate all subsets of given integers
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;   // To store the generated subsets
        vector<int> temp;           // Temporary vector to build subsets
        
        helper(ans, nums, nums.size(), temp, 0);  // Call the helper function
        return ans;   // Return the generated subsets
    }
};
