// Question Link: https://leetcode.com/problems/set-mismatch/

/*
645. Set Mismatch
Easy
3.9K
907
Companies
You have a set of integers s, which originally contains all the numbers from 1 to n. Unfortunately, due to some error, one of the numbers in s got duplicated to another number in the set, which results in repetition of one number and loss of another number.

You are given an integer array nums representing the data status of this set after the error.

Find the number that occurs twice and the number that is missing and return them in the form of an array.

Example 1:
Input: nums = [1,2,2,4]
Output: [2,3]
Example 2:
Input: nums = [1,1]
Output: [1,2]
 
Constraints:
2 <= nums.length <= 104
1 <= nums[i] <= 104
*/




class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {

        int n = nums.size();
        int i;

        sort(nums.begin(), nums.end());
        int res=0;
        int sum=0;
        int p1=0,p2=0;
        for(i=0;i<n;i++)
        {
            res = nums[i]^nums[i+1];
            if(res==0)
            {
                p1 = nums[i];
                break;
            }
        }

        nums[i]=0;

        for(i=0;i<n;i++)
        {
            sum+=nums[i];
        }
        int total = n*(n+1)/2;
         p2 = total-sum;
        

        vector<int> v{p1,p2};

        return v;
        
    }
};
