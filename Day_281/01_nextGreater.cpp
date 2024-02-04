// Question Link: https://www.interviewbit.com/problems/nextgreater/

/*
NEXTGREATER

Given an array, find the next greater element G[i] for every element A[i] in the array.  The Next greater Element for an element A[i] is the first greater element on the right side of A[i] in array. 
More formally,
G[i] for an element A[i] = an element A[j] such that 
    j is minimum possible AND 
    j > i AND
    A[j] > A[i]
Elements for which no greater element exist, consider next greater element as -1.

Example:
Input : A : [4, 5, 2, 10]
Output : [5, 10, 10, -1]
Example 2:
Input : A : [3, 2, 1]
Output : [-1, -1, -1]
*/



vector<int> Solution::nextGreater(vector<int> &A) {
    int n = A.size(); stack<int>s;
    vector<int>NGE(n, -1);
    for(int i=n-1; i>=0; i--){
        while(!s.empty() && s.top() <= A[i]) s.pop();
        if(!s.empty()) NGE[i] = s.top();
        s.push(A[i]);
    }
    return NGE;
}
