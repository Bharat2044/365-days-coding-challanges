// Question Link: https://www.interviewbit.com/problems/set-intersection/

/*
Set Intersection

Problem Description:
An integer interval [X, Y] (for integers X < Y) is a set of all consecutive integers from X to Y, including X and Y.
You are given a 2D array A with dimensions N x 2, where each row denotes an interval.
Find the minimum size of a set S such that for every integer interval Z in A, the intersection of S with Z has a size of at least two.

Problem Constraints:
1 <= N <= 105
1 <= A[i][0] < A[i][1] <= 109

Input Format:
The first argument is a 2D integer array A.

Output Format:
Return a single integer denoting the minimum size of S.

Example Input:
Input 1:
A = [[1, 3], [1, 4], [2, 5], [3, 5]]
Input 2:
A = [[1, 2], [2, 3], [2, 4], [4, 5]]

Example Output:
Output 1:
3
Output 2:
5

Example Explanation:
Explanation 1:
Consider the set S = {2, 3, 4}.  For each interval, there are at least 2 elements from S in the interval.
Also, there isn't a smaller size set that fulfills the above condition.
Thus, we output the size of this set, which is 3.
Explanation 2:
An example of a minimum sized set is {1, 2, 3, 4, 5}.
*/



// Comparator function for sorting intervals based on endpoint and startpoint
static bool cmp(vector<int> &a, vector<int> &b) {
    if (a[1] != b[1]) {
        // Sort by endpoint in ascending order
        return a[1] < b[1];
    }
    // If endpoints are equal, sort by startpoint in descending order
    return a[0] > b[0];
}

int Solution::setIntersection(vector<vector<int>> &A) {
    // Sort intervals based on endpoint and startpoint
    sort(A.begin(), A.end(), cmp);
    
    int cnt = 2; // Initial count for the first interval
    int n = A.size();
    pair<int, int> p;
    p.first = A[0][1] - 1; // Initialize the first element of the pair
    p.second = A[0][1];    // Initialize the second element of the pair
    
    // Iterate through the sorted intervals
    for (int i = 1; i < n; i++) {
        if (p.second < A[i][0]) {
            // If the start of the interval is greater than the current endpoint, add two elements to the set
            cnt += 2;
            p.second = A[i][1];
            p.first = p.second - 1;
        } else if (p.second == A[i][0]) {
            // If the end of the current interval is equal to the current endpoint, add one element to the set
            cnt++;
            p.first = p.second;
            p.second = A[i][1];
        } else if (p.first < A[i][0]) {
            // If the start of the current interval is greater than the first element of the pair, add one element to the set
            cnt++;
            if (p.second == A[i][1]) {
                p.first = p.second - 1;
            } else {
                p.first = p.second;
                p.second = A[i][1];
            }
        }
    }
    
    return cnt;
}
