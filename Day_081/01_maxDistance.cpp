// Question Link: https://www.interviewbit.com/problems/max-distance/

/*
Max Distance

Problem Description:
Given an array A of integers, find the maximum of j - i subjected to the constraint of A[i] <= A[j].

Problem Constraints:
1 <= |A| <= 106
-109 <= Ai <= 109

Input Format:
First and only argument is an integer array A.

Output Format:
Return an integer denoting the maximum value of j - i;

Example Input:
Input 1:
 A = [3, 5, 4, 2]

Example Output:
Output 1:
 2

Example Explanation:
Explanation 1:
 Maximum value occurs for pair (3, 4).
*/


int Solution::maximumGap(const vector<int> &A) {

    int n = A.size(), maxDist = 0, minPos = INT_MAX;

    vector<pair<int, int>> nums;

    for(int i=0; i<n; i++)
        nums.emplace_back(make_pair(A[i], i));

    sort(nums.begin(), nums.end());
    minPos = nums[0].second;    

    for(int i=1; i<n; i++) {
        if(nums[i].second > minPos)
            maxDist = max(maxDist, (nums[i].second - minPos));

        minPos = min(minPos, nums[i].second);
    }

    return maxDist;
}
