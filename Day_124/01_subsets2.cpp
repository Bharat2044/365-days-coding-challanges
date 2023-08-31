// Question Link: https://www.interviewbit.com/problems/subsets-ii/

/*
Subsets II

Given a collection of integers that might contain duplicates, S, return all possible subsets.

Note:
Elements in a subset must be in non-descending order.
The solution set must not contain duplicate subsets.
The subsets must be sorted lexicographically.

Example :
If S = [1,2,2], the solution is:
[
[],
[1],
[1,2],
[1,2,2],
[2],
[2, 2]
]
*/



void help(vector<int>& nums, int i, vector<vector<int>>& s, vector<int> temp){
        if(i == nums.size()){
            sort(begin(temp),end(temp));
            s.push_back(temp);
            return;
        }
        int j = i;
        while(j<nums.size()-1 && nums[j] == nums[j+1])
            // when ignoring current, ignore all others equivalent to current
            j++;
        help(nums, j+1, s, temp);
        temp.push_back(nums[i]);
        help(nums, i+1, s, temp);
    }

    vector<vector<int>> Solution::subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> s;
        vector<int> temp;
        sort(nums.begin(), nums.end());
        help(nums, 0, s, temp);
        sort(begin(s),end(s));
        
      return s;
    }
