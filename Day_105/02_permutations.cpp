// Question Link: https://leetcode.com/problems/permutations/

/*
46. Permutations

Given an array nums of distinct integers, return all the possible permutations. You can return the answer in any order.

Example 1:
Input: nums = [1,2,3]
Output: [[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]
Example 2:
Input: nums = [0,1]
Output: [[0,1],[1,0]]
Example 3:
Input: nums = [1]
Output: [[1]]
 
Constraints:
1 <= nums.length <= 6
-10 <= nums[i] <= 10
All the integers of nums are unique.
*/



class Solution {
public:
vector<vector<int>>ans;
    void solve(vector<int>& nums,vector<int>&per,int c){
        if(c==nums.size()){
            ans.push_back(per);
            return;
        }
        
        for(int i=0;i<nums.size();i++){
            if(per[i]==11){
                per[i]=nums[c];
                solve(nums,per,c+1);
                per[i]=11;
            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        int n=nums.size();
        vector<int>per(n,11);
        solve(nums,per,0);
        
        return ans;
    }
};
