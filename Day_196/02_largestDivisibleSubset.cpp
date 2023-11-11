// Question Link: https://leetcode.com/problems/largest-divisible-subset/

/*
368. Largest Divisible Subset

Given a set of distinct positive integers nums, return the largest subset answer such that every pair (answer[i], answer[j]) of elements in this subset satisfies:

answer[i] % answer[j] == 0, or
answer[j] % answer[i] == 0
If there are multiple solutions, return any of them.

Example 1:
Input: nums = [1,2,3]
Output: [1,2]
Explanation: [1,3] is also accepted.
Example 2:
Input: nums = [1,2,4,8]
Output: [1,2,4,8]
 
Constraints:
1 <= nums.length <= 1000
1 <= nums[i] <= 2 * 109
All the integers in nums are unique.
*/



class Solution {
public:
    
    vector<int> largestDivisibleSubset(vector<int>& arr) {
        int n=arr.size();
        vector<int>dp(n,1),hash(n);
        int li=0;
        int maxi=1;
        sort(arr.begin(),arr.end());
        for(int i=0;i<n;i++){
            hash[i]=i;
            for(int prev=0;prev<i;prev++){
                if(arr[i]%arr[prev]==0 && 1+dp[prev]>dp[i]){
                    dp[i]=1+dp[prev];
                    hash[i]=prev;
                }
            }
            if(dp[i]>maxi){
                maxi=dp[i];
                li=i;
            }
        }
        vector<int>res(maxi);
        int i=1;
        res[0]=arr[li];
        while(hash[li]!=li){
            li=hash[li];
            res[i]=arr[li];
            i++;
        }
        // return hash;
        reverse(res.begin(),res.end());
        return res;
    }
};
