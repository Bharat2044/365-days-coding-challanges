// Question Link: https://leetcode.com/problems/trapping-rain-water/

/*
42. Trapping Rain Water:

Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it can trap after raining. 

Example 1:
Input: height = [0,1,0,2,1,0,1,3,2,1,2,1]
Output: 6
Explanation: The above elevation map (black section) is represented by array [0,1,0,2,1,0,1,3,2,1,2,1]. In this case, 6 units of rain water (blue section) are being trapped.
Example 2:
Input: height = [4,2,0,3,2,5]
Output: 9 

Constraints:
n == height.length
1 <= n <= 2 * 104
0 <= height[i] <= 105
*/


// Time Complexity = O(n), Space Complexity = O(n)
class Solution {
public:
    int trap(vector<int>& height) {
    int n = height.size(), ans = 0;
       vector<int> l_max(n), r_max(n);
        
       l_max[0] = height[0];
       for (int i=1; i<n; ++i) 
           l_max[i] = max(l_max[i-1], height[i]);
        
       r_max[n-1] = height[n-1];        
       for(int i=n-2; i>=0; --i) 
           r_max[i] = max(r_max[i+1], height[i]);
        
       for(int i=0; i<n; ++i) 
           ans += min(l_max[i], r_max[i])-height[i];
        
       return ans;
    }
};
