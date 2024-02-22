// Question Link: https://www.interviewbit.com/problems/longest-consecutive-sequence/

/*
Longest Consecutive Sequence

Given an unsorted array of integers, find the length of the longest consecutive elements sequence.

Example: 
Given [100, 4, 200, 1, 3, 2],

The longest consecutive elements sequence is [1, 2, 3, 4]. Return its length: 4.

Your algorithm should run in O(n) complexity.
*/


int Solution::longestConsecutive(const vector<int> &A) {
    unordered_map<int,bool> mp;
    int n = A.size();
    for(int i = 0; i<n; i++)
    {
        mp[A[i]] = 1;
    }
    for(auto it : mp)
    {
        if(mp.find(it.first-1) != mp.end()) mp[it.first] = 0;
    }
    int mxl = 1;
    int st = -1;
    int omx = 0;
    for(auto it : mp)
    {
        if(it.second == 1)
        {
            int tl = 1;
            st = it.first;
            mxl = 1;
            while(mp.find(it.first +tl) != mp.end())
            {
                mxl++;
                tl++;
            }
        }
        omx = max(mxl,omx);
    }
    return omx;
}
