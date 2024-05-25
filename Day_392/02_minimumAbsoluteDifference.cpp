// Question Link: https://leetcode.com/problems/minimum-absolute-difference/description/

/*
1200. Minimum Absolute Difference

Given an array of distinct integers arr, find all pairs of elements with the minimum absolute difference of any two elements.

Return a list of pairs in ascending order(with respect to pairs), each pair [a, b] follows
a, b are from arr
a < b
b - a equals to the minimum absolute difference of any two elements in arr
 
Example 1:
Input: arr = [4,2,1,3]
Output: [[1,2],[2,3],[3,4]]
Explanation: The minimum absolute difference is 1. List all pairs with difference equal to 1 in ascending order.
Example 2:
Input: arr = [1,3,6,10,15]
Output: [[1,3]]
Example 3:
Input: arr = [3,8,-10,23,19,-4,-14,27]
Output: [[-14,-10],[19,23],[23,27]]
 
Constraints:
2 <= arr.length <= 10^5
-10^6 <= arr[i] <= 10^6
*/



class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        vector<vector<int>>res;
       int n=arr.size();
        sort(arr.begin(),arr.end());
        int D=INT_MAX;
      for(int i=1;i<n;i++){
          D=min(D,arr[i]-arr[i-1]);
          
      }
        for(int i=1;i<arr.size();i++){
            if(arr[i]-arr[i-1]==D){
                vector<int>v{arr[i-1],arr[i]};
               res.push_back(v);
            }
        }
        return res;
    }
};
