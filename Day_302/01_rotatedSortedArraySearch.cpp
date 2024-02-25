// Question Link: https://www.interviewbit.com/problems/rotated-sorted-array-search/

/*
Rotated Sorted Array Search

Problem Description:
Given an array of integers A of size N and an integer B.
array A is rotated at some pivot unknown to you beforehand.
(i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2 ).
You are given a target value B to search. If found in the array, return its index, otherwise, return -1.
You may assume no duplicate exists in the array.
NOTE:- Array A was sorted in non-decreasing order before rotation.
Think about the case when there are duplicates. Does your current solution work? How does the time complexity change?

Problem Constraints:
1 <= N <= 1000000
1 <= A[i] <= 10^9
1 <= B <= 10^9
all elements in A are distinct.

Input Format:
The first argument given is the integer array A.
The second argment given is the integer B.

Output Format:
Return index of B in array A, otherwise return -1

Example Input:
Input 1: 
A = [4, 5, 6, 7, 0, 1, 2, 3]
B = 4 
Input 2: 
A = [5, 17, 100, 3]
B = 6

Example Output:
Output 1: 
 0 
Output 2: 
 -1

Example Explanation:
Explanation 1:
Target 4 is found at index 0 in A. 
Explanation 2:
Target 6 is found not found in the array A = [5, 17, 100, 3].
*/



int Solution::search(const vector<int> &A, int B) {
    int n = A.size();
    int low = 0,high=n-1;
    while(low<=high){
        int mid = (low+high)/2;
        if(A[mid]==B)return mid;
        if(A[mid]>=A[low]){
            if(A[low]<=B && B<=A[mid])high=mid-1;
            else low = mid+1;
        }
        else {
            if(A[mid]<=B && A[high]>=B)low=mid+1;
            else high = mid-1;
        }
    }
    return -1;
}
