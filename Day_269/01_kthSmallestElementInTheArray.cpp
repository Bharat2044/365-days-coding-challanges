// Question Link: https://www.interviewbit.com/problems/kth-smallest-element-in-the-array/

/*
Kth Smallest Element in the Array

Problem Description:
Find the Bth smallest element in an unsorted array of non-negative integers A.
Definition of kth smallest element: The kth smallest element is the minimum possible n such that there are at least k elements in the array <= n.
In other words, if the array A was sorted, then Ak - 1

NOTE: You are not allowed to modify the array (The array is read-only). Try to do it using constant extra space.

Problem Constraints:
1 <= |A| <= 106
1 <= B <= |A|
1 <= A[i] <= 109

Input Format:
The first argument is an integer array A.
The second argument is integer B.

Output Format:
Return the Bth smallest element in given array.

Example Input:
Input 1:
A = [2, 1, 4, 3, 2]
B = 3
Input 2:
A = [1, 2]
B = 2

Example Output:
Output 1:
 2
Output 2:
 2

Example Explanation:
Explanation 1:
 3rd element after sorting is 2.
Explanation 2:
 2nd element after sorting is 2.
*/



int Solution::kthsmallest(const vector<int> &A, int B) {
    priority_queue<int> maxH;
    
    for(int i = 0; i < A.size(); i++){
        maxH.push(A[i]);
        
        if(maxH.size() > B)
            maxH.pop();
    }    
    
    return maxH.top();
}
