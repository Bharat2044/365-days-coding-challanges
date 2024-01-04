// Question Link: https://leetcode.com/problems/minimum-time-difference/

/*
539. Minimum Time Difference

Given a list of 24-hour clock time points in "HH:MM" format, return the minimum minutes difference between any two time-points in the list.
 
Example 1:
Input: timePoints = ["23:59","00:00"]
Output: 1
Example 2:
Input: timePoints = ["00:00","23:59","00:00"]
Output: 0
 
Constraints:
2 <= timePoints.length <= 2 * 104
timePoints[i] is in the format "HH:MM".
*/


class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        vector<int> mins(1440);
        for(string t : timePoints) {
            int h = stoi(t.substr(0, 2));
            int m = stoi(t.substr(3));
            
            if(mins[h * 60 + m]) return 0;
            mins[h * 60 + m] = 1;
        }
        int ans = 1e9, pre = -1, s = 1e9, e = -1e9;
        for(int i=0; i<mins.size(); i++) {
            if(mins[i]) {
                if(pre == -1) pre = i;
                else ans = min(ans, i - pre), pre = i;
                s = min(s, i);
                e = max(e, i);
            }
        }
        return min(ans, 1440 - (e - s));
    }
};
