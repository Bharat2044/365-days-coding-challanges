// Question Link: https://leetcode.com/problems/non-overlapping-intervals/

/*
435. Non-overlapping Intervals

Given an array of intervals intervals where intervals[i] = [starti, endi], return the minimum number of intervals you need to remove to make the rest of the intervals non-overlapping.

Example 1:
Input: intervals = [[1,2],[2,3],[3,4],[1,3]]
Output: 1
Explanation: [1,3] can be removed and the rest of the intervals are non-overlapping.
Example 2:
Input: intervals = [[1,2],[1,2],[1,2]]
Output: 2
Explanation: You need to remove two [1,2] to make the rest of the intervals non-overlapping.
Example 3:
Input: intervals = [[1,2],[2,3]]
Output: 0
Explanation: You don't need to remove any of the intervals since they're already non-overlapping.
 
Constraints:
1 <= intervals.length <= 105
intervals[i].length == 2
-5 * 104 <= starti < endi <= 5 * 104
*/



class Solution {
public:
    static bool cmp(const pair<int, int>& a, const pair<int, int>&b){
        return a.second < b.second;
    }
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        if (intervals.size() == 0) {
            return 0;
        }
        int n = intervals.size();
        vector<pair<int, int>> v(n);
        for(int i=0; i<n; i++){
            v[i].first = intervals[i][0];
            v[i].second = intervals[i][1];
        }
        sort(v.begin(), v.end(), cmp);

        int end = v[0].second;
        int count = 0; 

        for(int i=1; i<n; i++){
            if(v[i].first < end){
                count++;
            } else {
                end = v[i].second;
            }
        }
        
        return count;
    }
};


