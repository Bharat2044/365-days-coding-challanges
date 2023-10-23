// Question Link: https://www.interviewbit.com/problems/combination-sum-ii/
 
/*
Combination Sum II

Given a collection of candidate numbers (C) and a target number (T), find all unique combinations in C where the candidate numbers sums to T.

Each number in C may only be used once in the combination.

Note:
All numbers (including target) will be positive integers.
Elements in a combination (a1, a2, … , ak) must be in non-descending order. (ie, a1 ≤ a2 ≤ … ≤ ak).
The solution set must not contain duplicate combinations.

Example :
Given candidate set 10,1,2,7,6,1,5 and target 8,

A solution set is:
[1, 7]
[1, 2, 5]
[2, 6]
[1, 1, 6]
Warning : DO NOT USE LIBRARY FUNCTION FOR GENERATING COMBINATIONS.

Example : itertools.combinations in python.
If you do, we will disqualify your submission retroactively and give you penalty points.
*/



void solve(vector<int>& nums, int target, int index, vector<int>& comb, 
    set<vector<int>>& ans) {
    // base case
    if (target == 0) {
        ans.insert(comb);
        return;
    }
    
    if (target < 0 || index >= nums.size()) return;
    
    // 2 choices, either include the current element or exclude.
    // include
    comb.push_back(nums[index]);
    solve(nums, target - nums[index], index + 1, comb, ans);
    comb.pop_back(); // backtrack
    // exclude
    solve(nums, target, index + 1, comb, ans);
}

vector<vector<int> > Solution::combinationSum(vector<int> &A, int B) {
    sort(A.begin(), A.end());
    set<vector<int>> ans;
    vector<int> comb;
    solve(A, B, 0, comb, ans);
    vector<vector<int>> res;
    for (auto it: ans) {
        vector<int> t;
        for (auto i: it) {
            t.push_back(i);
        }
        res.push_back(t);
    }
    return res;
}
