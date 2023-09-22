// Question Link: https://leetcode.com/problems/subsets-ii/

/*
90. Subsets II

Given an integer array nums that may contain duplicates, return all possible subsets (the power set).

The solution set must not contain duplicate subsets. Return the solution in any order.

Example 1:
Input: nums = [1,2,2]
Output: [[],[1],[1,2],[1,2,2],[2],[2,2]]
Example 2:
Input: nums = [0]
Output: [[],[0]]
 
Constraints:
1 <= nums.length <= 10
-10 <= nums[i] <= 10
*/




class Solution {
public:
    void fun(vector<int>& nums, int index, vector<int>ds, set<vector<int>>& res) {
        if(index == nums.size()) {
            res.insert(ds);
            return;
        }
        ds.push_back(nums[index]);
        fun(nums, index+1, ds, res);
        ds.pop_back();
        fun(nums, index+1, ds, res);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        set<vector<int>> res;
        vector<int> ds;
        fun(nums, 0, ds, res);
        for(auto it = res.begin(); it!= res.end(); it++) {
            ans.push_back(*it);
        }  
        return ans;
    }
};
