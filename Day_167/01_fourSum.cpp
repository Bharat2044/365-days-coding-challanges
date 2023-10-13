// Question Link: https://www.interviewbit.com/problems/4-sum/

/*
4 Sum

Given an array S of n integers, are there elements a, b, c, and d in S such that a + b + c + d = target? Find all unique quadruplets in the array which gives the sum of target.

Note:
Elements in a quadruplet (a,b,c,d) must be in non-descending order. (ie, a ≤ b ≤ c ≤ d)
The solution set must not contain duplicate quadruplets.

Example : 
Given array S = {1 0 -1 0 -2 2}, and target = 0
A solution set is:
    (-2, -1, 1, 2)
    (-2,  0, 0, 2)
    (-1,  0, 0, 1)
Also make sure that the solution set is lexicographically sorted.

Solution[i] < Solution[j] iff Solution[i][0] < Solution[j][0] OR (Solution[i][0] == Solution[j][0] AND ... Solution[i][k] < Solution[j][k])
*/



vector<vector<int> > Solution::fourSum(vector<int> &nums, int target) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        set<vector<int>> st;
        
        for(int i = 0; i < n-3; i++){
            for(int j = i+1; j < n-2; j++){
                long long newtar = (long long)target - ((long long)nums[i] + (long long)nums[j]);
                int l = j+1, r = n-1;
              
                while(l < r){
                    if(nums[l] + nums[r] < newtar){
                        l++;
                    }else if(nums[l] + nums[r] > newtar){
                        r--;
                    }else{
                        st.insert({nums[i], nums[j], nums[l], nums[r]});
                        l++;
                        r--;
                    }
                }
            }
        }
  
        for(auto it : st) 
          ans.push_back(it);

        return ans;
}
