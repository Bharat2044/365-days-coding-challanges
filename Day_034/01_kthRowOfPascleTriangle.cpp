// Question Link: https://www.interviewbit.com/problems/kth-row-of-pascals-triangle/

/*
Kth Row of Pascal's Triangle:

Problem Description:
Given an index k, return the kth row of the Pascal's triangle.
Pascal's triangle: To generate A[C] in row R, sum up A'[C] and A'[C-1] from previous row R - 1.

Example:
Input : k = 3

Return : [1,3,3,1]

Note: k is 0 based. k = 0, corresponds to the row [1]. 

Note: Could you optimize your algorithm to use only O(k) extra space?
*/



vector<int> Solution::getRow(int A) {
    vector<int> ans;
    
    int res = 1;
    ans.push_back(res);
    
    for(int i=0; i<A; i++){
        res *= (A - i);
        res /= (i + 1);
        ans.push_back(res);
    }
    
    return ans;
}
