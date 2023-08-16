// Question Link: https://www.interviewbit.com/problems/combination-sum/

/*
Combination Sum

Problem Description:
Given an array of candidate numbers A and a target number B, find all unique combinations in A where the candidate numbers sums to B.

The same repeated number may be chosen from A unlimited number of times.

Note:
1) All numbers (including target) will be positive integers.

2) Elements in a combination (a1, a2, … , ak) must be in non-descending order. (ie, a1 ≤ a2 ≤ … ≤ ak).

3) The combinations themselves must be sorted in ascending order.

4) CombinationA > CombinationB iff (a1 > b1) OR (a1 = b1 AND a2 > b2) OR ... (a1 = b1 AND a2 = b2 AND ... ai = bi AND ai+1 > bi+1)

5) The solution set must not contain duplicate combinations.

Problem Constraints:
1 <= |A| <= 20 
1 <= A[i] <= 50
1 <= B <= 500

Input Format:
The first argument is an integer array A.
The second argument is integer B.

Output Format:
 Return a vector of all combinations that sum up to B.

Example Input:
Input 1:
A = [2, 3]
B = 2
Input 2:
A = [2, 3, 6, 7]
B = 7

Example Output:
Output 1:
[ [2] ]
Output 2:
[ [2, 2, 3] , [7] ]


Example Explanation:
Explanation 1:
All possible combinations are listed.
Explanation 2:
All possible combinations are listed.
*/



void combination(vector<int>& candidates, int target, vector<int> currComb, int currSum, int currIndex,vector<vector<int>>& ans) {
        if(currSum>target) 
            return; 

        if(currSum==target){
            ans.push_back(currComb); 
            return;
        }

        for(int i=currIndex; i<candidates.size(); i++) {
            if(i>currIndex && candidates[i]==candidates[i-1])
                continue; 

            currComb.push_back(candidates[i]); 
            currSum+=candidates[i];
            
            combination(candidates, target, currComb, currSum, i, ans); 
            currComb.pop_back(); 
            currSum-=candidates[i];
        }
    }

    vector<vector<int> > Solution::combinationSum(vector<int> &candidates, int target ) {
        sort(candidates.begin(),candidates.end());
        vector<vector<int>> ans;

        vector<int> currComb;
        combination(candidates, target, currComb, 0, 0, ans); 

        sort(ans.begin(),ans.end());

        return ans;
}
