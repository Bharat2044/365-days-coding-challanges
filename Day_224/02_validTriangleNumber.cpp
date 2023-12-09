// Question Link: https://leetcode.com/problems/valid-triangle-number/

/*
611. Valid Triangle Number

Given an integer array nums, return the number of triplets chosen from the array that can make triangles if we take them as side lengths of a triangle.

Example 1:
Input: nums = [2,2,3,4]
Output: 3
Explanation: Valid combinations are: 
2,3,4 (using the first 2)
2,3,4 (using the second 2)
2,2,3
Example 2:
Input: nums = [4,2,3,4]
Output: 4
 
Constraints:
1 <= nums.length <= 1000
0 <= nums[i] <= 1000
*/



class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        
        sort(nums.begin(),nums.end());
        reverse(nums.begin(),nums.end());
        
        int n=nums.size();
        int cnt=0;
        
        for(int i=0;i<n;i++){
            int j=i+1,k=n-1;
         
            while(j<k){
                int a=nums[i],b=nums[j],c=nums[k];
                if(b+c > a){
                    cnt+=k-j;
                    j++;
                }
                else{
                    k--;
                }
            }
        }
        return cnt;
    }
};
