// Question Link: https://www.interviewbit.com/problems/rotated-array/

/*
Rotated Array

Problem Description:
Suppose a sorted array A is rotated at some pivot unknown to you beforehand.

(i.e., 1 2 4 5 6 7 might become 4 5 6 7 1 2).

Find the minimum element.

The array will not contain duplicates.

Note:- Use the circular rotated property of the array to solve the problem.

Problem Constraints:
1 <= len(A) <= 105
1 <= A[i] <= 109

Input Format:
The first argument is an Integer array A.

Output Format:
Return the minimum element of array A.

Example Input:
Input 1:-
A = [7, 2, 4, 5]
Input 2:-
A = [3, 1, 2]

Example Output:
Output 1:-
2
Output 2:-
1

Example Explanation:
Explanation 1:-
2 is the minimum element in the aray.
Explanation 2:-
1 is the minimum element in the array.
*/



int Solution::findMin(const vector<int> &A) {
    int low = 0, high = A.size()-1;
    
    while(low <= high) {
        int mid = (low + high)/2;        

        if((mid == 0 || A[mid] < A[mid-1]) && (mid == A.size()-1 || A[mid] < A[mid+1]))
            return A[mid];
        else if(A[mid] > A[high])  
            low = mid+1;
        else 
            high = mid-1;
    }

    return -1; 

}
