// Question Link: https://leetcode.com/problems/target-sum/

/*
494. Target Sum

You are given an integer array nums and an integer target.
You want to build an expression out of nums by adding one of the symbols '+' and '-' before each integer in nums and then concatenate all the integers.

For example, if nums = [2, 1], you can add a '+' before 2 and a '-' before 1 and concatenate them to build the expression "+2-1".
Return the number of different expressions that you can build, which evaluates to target.

Example 1:
Input: nums = [1,1,1,1,1], target = 3
Output: 5
Explanation: There are 5 ways to assign symbols to make the sum of nums be target 3.
-1 + 1 + 1 + 1 + 1 = 3
+1 - 1 + 1 + 1 + 1 = 3
+1 + 1 - 1 + 1 + 1 = 3
+1 + 1 + 1 - 1 + 1 = 3
+1 + 1 + 1 + 1 - 1 = 3
Example 2:
Input: nums = [1], target = 1
Output: 1
 
Constraints:
1 <= nums.length <= 20
0 <= nums[i] <= 1000
0 <= sum(nums[i]) <= 1000
-1000 <= target <= 1000
*/



class Solution {
public:

    int f(int index, int target, vector<int> &nums, vector<vector<int>> &dp){
        // base cases.
        if (index==0) {
            if (target==0 && nums[index]==0) return 2;
            if (nums[index]==target || target==0) return 1;
            return 0;
        }
        // yoyo dp
        if(dp[index][target]!=-1) return dp[index][target];
        // Pick case.
        int Pick=0;
        if (nums[index]<=target) Pick=f(index-1, target-nums[index], nums, dp);
        // not Pick case
        int notPick=f(index-1, target, nums, dp);

        return dp[index][target] = Pick+notPick;

    }

    int tab(int n, int k, vector<int> &nums){
        vector<int> prev(k+1, 0), curr(k+1, 0);

        if (nums[0]==0) prev[0]=2;
        else prev[0]=1;

        if (nums[0]!=0 && nums[0]<=k) prev[nums[0]]=1;

        for (int index=1; index<n; index++){
            for (int target=0; target<=k; target++){
                int Pick=0;
                if (nums[index]<=target) Pick=prev[target-nums[index]];
                // not Pick case
                int notPick=prev[target];

                curr[target] = Pick+notPick;
            }
            prev=curr;
        }return prev[k];
    }

    int findTargetSumWays(vector<int>& nums, int target) {
        int sum=accumulate(nums.begin(), nums.end(), 0);
        int k=(sum-target);
        if (k<0 || k%2!=0){
            return 0;
        }

        int n=nums.size();
        //vector<vector<int>> dp(n, vector<int> (k+1, -1));
        //return f(n-1, k/2, nums, dp);
        return tab(n, k/2, nums);

    }
};
