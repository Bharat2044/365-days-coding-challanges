// Question Link: https://leetcode.com/problems/insert-interval/

/*
57. Insert Interval

You are given an array of non-overlapping intervals intervals where intervals[i] = [starti, endi] represent the start and the end of the ith interval and intervals is sorted in ascending order by starti. You are also given an interval newInterval = [start, end] that represents the start and end of another interval.

Insert newInterval into intervals such that intervals is still sorted in ascending order by starti and intervals still does not have any overlapping intervals (merge overlapping intervals if necessary).

Return intervals after the insertion.

Example 1:
Input: intervals = [[1,3],[6,9]], newInterval = [2,5]
Output: [[1,5],[6,9]]
Example 2:
Input: intervals = [[1,2],[3,5],[6,7],[8,10],[12,16]], newInterval = [4,8]
Output: [[1,2],[3,10],[12,16]]
Explanation: Because the new interval [4,8] overlaps with [3,5],[6,7],[8,10].
 
Constraints:
0 <= intervals.length <= 104
intervals[i].length == 2
0 <= starti <= endi <= 105
intervals is sorted by starti in ascending order.
newInterval.length == 2
0 <= start <= end <= 105
*/



class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInter) {
        int n = intervals.size();
        vector<vector<int>> ans;
        int ii = 0;
        for( int i=n-1; i>=0; i--){
            if(newInter[0] > intervals[i][0]){
                ii = i+1;
                break;
            }
        }

        intervals.push_back(newInter);
        for(int i=(n+1)-1; i>ii; i--){
            swap(intervals[i],intervals[i-1]);
        }
        //merge intervals
        ans.push_back(intervals[0]);
        int last;
        for( int i=1;i<n+1;i++){
            if(ans.back()[1]  < intervals[i][0]){ //if gap btw them
                ans.push_back(intervals[i]);
            }
            else if(ans.back()[1]  >= intervals[i][0]){ //if overlapping
                last = max(ans.back()[1],intervals[i][1]);
                ans.back()[1] = last;
            }
        }
        return ans;
    }
};
