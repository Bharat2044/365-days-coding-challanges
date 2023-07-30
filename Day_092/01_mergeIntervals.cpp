// Question Link: https://www.interviewbit.com/problems/merge-intervals/

/*
Merge Intervals

Problem Description:
Given a set of non-overlapping intervals and a new interval.

Insert the new interval into the set of intervals (merge if necessary).

You may assume that the intervals were initially sorted according to their start times.
Note: Make sure the returned intervals are also sorted.

Problem Constraints:
0 <= |intervals| <= 106
1 <= intervalsi.start < intervalsi.end <= 109
1 <= newInterval.start < newInteval.end <= 109

Input Format:
The First argument is an array of Intervals.
The second argument is the new Interval.

Output Format:
Return the array of merged intervals.

Example Input:
Input 1:
Intervals = [[1,3],[6,9]]
newInterval = [2,5]
Input 2:
Intervals = [[1,2],[3,5],[6,7],[8,10],[12,16]]
newInterval = [4,9]

Example Output:
Output 1:
[[1,5],[6,9]]
Output 2:
[1,2],[3,10],[12,16]

Example Explanation:
Explanation 1:
Given intervals [1,3],[6,9] insert and merge [2,5] would result in [1,5],[6,9].
Explanation 2:
Given [1,2],[3,5],[6,7],[8,10],[12,16], insert and merge [4,9] would result in [1,2],[3,10],[12,16].
This is because the new interval [4,9] overlaps with [3,5],[6,7],[8,10].
*/




/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
vector<Interval> Solution::insert(vector<Interval> &intervals, Interval newInterval) {
   
    // [3,4] , [5 , 6] , [7 , 8] -> [1, 9] .. [1,2] .. [2,5]
   
    // condition of overlapping is -> last interval is p , then p.end >= intervals[i].start
   
    // new formed overlapped interval is -> {min(p.start , intervals[i].start) , max(p.end , intervals[i].end)}
   
    // newly overlapped interval will be replaced by its old value at res[res.size()-1] , i.e last value of res from
    // which we are comparing \
   
    vector<Interval> res;
   
    if(newInterval.start > newInterval.end) {
        Interval p={newInterval.end , newInterval.start};
        newInterval=p;
    }
   
    res.push_back(newInterval);
   
    for(int i=0;i<intervals.size();i++) {
        int sz=res.size();       
        Interval last=res[sz-1];
       
        if((last.start<=intervals[i].end  && intervals[i].start <= last.start) || (intervals[i].start<=last.end && intervals[i].start>=last.start ))        
            res[sz-1]={min(last.start , intervals[i].start) , max(last.end , intervals[i].end)};
        
        else {
            if(intervals[i].end<last.start) {
                res[sz-1]=intervals[i];
                res.push_back(last);
            }
           
            if(intervals[i].start > last.end)
                res.push_back(intervals[i]);            
        }
    }
    
   return res;
}



