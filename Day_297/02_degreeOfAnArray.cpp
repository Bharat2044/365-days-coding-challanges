// Question Link: https://leetcode.com/problems/degree-of-an-array/

/*
697. Degree of an Array

Given a non-empty array of non-negative integers nums, the degree of this array is defined as the maximum frequency of any one of its elements.
Your task is to find the smallest possible length of a (contiguous) subarray of nums, that has the same degree as nums.

Example 1:
Input: nums = [1,2,2,3,1]
Output: 2
Explanation: 
The input array has a degree of 2 because both elements 1 and 2 appear twice.
Of the subarrays that have the same degree:
[1, 2, 2, 3, 1], [1, 2, 2, 3], [2, 2, 3, 1], [1, 2, 2], [2, 2, 3], [2, 2]
The shortest length is 2. So return 2.
Example 2:
Input: nums = [1,2,2,3,1,4,2]
Output: 6
Explanation: 
The degree is 3 because the element 2 is repeated 3 times.
So [2,2,3,1,4,2] is the shortest subarray, therefore returning 6.
 
Constraints:
nums.length will be between 1 and 50,000.
nums[i] will be an integer between 0 and 49,999.
*/



class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        unordered_map<int, vector<int>> degree;
        // storing max degree
        int m = 0;
        // storing length of subarray
        int k = nums.size();

        for(int i=0; i<nums.size(); i++) {
            // assign vector of size 2 for every new element
            // 1- degree of the element 2- first position of element
            if(degree.find(nums[i]) == degree.end())
                degree[nums[i]] = vector<int>(2);
            
            // increment degree of the element and
            // if its first occurred than fill its first position
            if(++degree[nums[i]][0] == 1)
                degree[nums[i]][1] = i;

            // update degree of array and length of subarray when
            // degree of the element is greater
            if(degree[nums[i]][0] > m) {
                m = degree[nums[i]][0];
                k = i - degree[nums[i]][1] + 1;
            }
            // update k when there are elements with same max degree
            else if(degree[nums[i]][0] == m)
                k = min(k, i - degree[nums[i]][1] + 1);
        }
        
        return k;
    }
};
