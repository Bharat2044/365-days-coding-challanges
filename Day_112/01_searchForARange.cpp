// Qustion Link: https://www.interviewbit.com/problems/search-for-a-range/

/*
Search for a Range

Problem Description:
Given a sorted array of integers A(0 based index) of size N, find the starting and the ending position of a given integer B in array A.

Your algorithm's runtime complexity must be in the order of O(log n).

Return an array of size 2, such that the first element = starting position of B in A and the second element = ending position of B in A, if B is not found in A return [-1, -1].

Problem Constraints:
1 <= N <= 106
1 <= A[i], B <= 109

Input Format:
The first argument given is the integer array A.
The second argument given is the integer B.

Output Format:
Return an array of size 2, such that the first element = starting position of B in A and the second element = the ending position of B in A if B is not found in A return [-1, -1].

Example Input:
Input 1:
 A = [5, 7, 7, 8, 8, 10]
 B = 8
Input 2:
 A = [5, 17, 100, 111]
 B = 3

Example Output:
Output 1:
 [3, 4]
Output 2:
 [-1, -1]

Example Explanation:
Explanation 1:
 The first occurence of 8 in A is at index 3.
 The second occurence of 8 in A is at index 4.
 ans = [3, 4]
Explanation 2:
 There is no occurence of 3 in the array.
*/



vector<int> Solution::searchRange(const vector<int> &A, int B) {
    int start = 0;
    int end = A.size() - 1;
    vector<int> v;
    int mid;
    int x=-1;
  
    while (start <= end) {
        mid = start + (end - start) / 2;
        if (A[mid] == B) {
            x=mid;
            end = mid - 1;
        } else if (A[mid] > B) {
            end = mid - 1;
        } else {
            start = mid + 1;
        }
    }
  
    v.push_back(x);
    int y=-1;

    start = 0;
    end = A.size() - 1;
    
    while (start <= end) {
        mid = start + (end - start) / 2;
        if (A[mid] == B) {
            y=mid;
            start = mid + 1;
        } else if (A[mid] > B) {
            end = mid - 1;
        } else {
            start = mid + 1;
        }
    }
    v.push_back(y);

    return v;
}
