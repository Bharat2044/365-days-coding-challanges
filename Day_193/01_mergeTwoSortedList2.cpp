// Question Link: https://www.interviewbit.com/problems/merge-two-sorted-lists-ii/

/*
Merge Two Sorted Lists II

Problem Description:
Given two sorted integer arrays A and B, merge B into A as one sorted array.

Note: You have to modify the array A to contain the merge of A and B. Do not output anything in your code.
TIP: C users, please malloc the result into a new array and return the result.

If the number of elements initialized in A and B is m and n respectively, the resulting size of array A after your code is executed should be m + n

Problem Constraints:
1 <= |A|, |B| <= 105

Input Format:
The first argument is an integer array A.
The second argument is an integer array B.

Output Format:
Update the array A.

Example Input:
A : [1 5 8]
B : [6 9]

Example Output:
Modified A : [1 5 6 8 9]
*/



void Solution::merge(vector<int> &A, vector<int> &B) {

    A.insert(A.end(),B.begin(),B.end());

    sort(A.begin(),A.end());
}
