// Question Link: https://www.interviewbit.com/problems/largest-rectangle-in-histogram/

/*
Largest Rectangle in Histogram

Problem Description:
Given an array of integers A .

A represents a histogram i.e A[i] denotes height of the ith histogram's bar. Width of each bar is 1.

Find the area of the largest rectangle formed by the histogram.

Problem Constraints:
1 <= |A| <= 100000
1 <= A[i] <= 1000000000

Input Format:
The only argument given is the integer array A.

Output Format:
Return the area of largest rectangle in the histogram.

Example Input:
Input 1:
 A = [2, 1, 5, 6, 2, 3]
Input 2:
 A = [2]
 
Example Output:
Output 1:
 10
Output 2:
 2

Example Explanation:
Explanation 1:
The largest rectangle has area = 10 unit. Formed by A[3] to A[4].
Explanation 2:
Largest rectangle has area 2.
*/



int Solution::largestRectangleArea(vector<int> &A) {
    A.push_back(0);
    int n = A.size();
    
    stack<pair<int, int>> st;
    st.push({-1, -1});
    int maximum = 0;
    
    for (int i = 0; i < n; i++) {
        if (A[i] <= st.top().first) {
            while (st.top().first >= A[i]) {
                int ht = st.top().first;
                int ind = st.top().second;
                st.pop();
                maximum = max(maximum, (i - st.top().second - 1) * ht);
            }
        }
        st.push({A[i], i});
    }
    
    return maximum;
}
