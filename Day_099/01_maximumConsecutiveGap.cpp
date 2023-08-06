// Question Link: https://www.interviewbit.com/problems/maximum-consecutive-gap/

/*
Maximum Consecutive Gap

Problem Description:
Given an unsorted array, find the maximum difference between the successive elements in its sorted form.
Return 0 if the array contains less than 2 elements.
You may assume that all the elements in the array are non-negative integers and fit in the 32-bit signed integer range.
You may also assume that the difference will not overflow.
Try to solve it in linear time/space

Problem Constraints:
1 <= |A| <= 106
1 <= Ai <= 109

Input Format:
The first argument is an integer array A.

Output Format:
Return an integer representing maximum difference between the successive elements in array A.

Example Input:
A = [1, 10, 5]

Example Output:
5

Example Explanation:
The maximum difference is between 5 and 10, which is 5.
*/




int Solution::maximumGap(const vector<int> &A) {
    int n = A.size();
    int dif = 0;
    vector<int> v;
    
    copy(A.begin(), A.end(), back_inserter(v));
    sort(v.begin(), v.end());
    
    if(n < 2)
        return 0;
            
    for(int i=0; i<n-1; i++)
        dif=max(dif, abs(v[i]-v[i+1]));
    
    return dif;
}
