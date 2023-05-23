// Question Link: https://www.interviewbit.com/problems/intersection-of-sorted-arrays/

/*
Intersection Of Sorted Arrays:

Problem Description:
Find the intersection of two sorted arrays OR in other words, given 2 sorted arrays, find all the elements which occur in both arrays.

NOTE: For the purpose of this problem ( as also conveyed by the sample case ), assume that elements that appear more than once in both arrays should be included multiple times in the final output.

Problem Constraints:
1 <= |A| <= 106
1 <= |B| <= 106

Input Format:
The first argument is an integer array A.
The second argument is an integer array B.

Output Format:
Return an array of intersection of the two arrays.

Example Input:
Input 1:
A: [1 2 3 3 4 5 6]
B: [3 3 5]
Input 2:
A: [1 2 3 3 4 5 6]
B: [3 5]

Example Output:
Output 1: [3 3 5]
Output 2: [3 5]

Example Explanation:
Explanation 1:
3, 3, 5 occurs in both the arrays A and B
Explanation 2:
Only 3 and 5 occurs in both the arrays A and B
*/



vector<int> Solution::intersect(const vector<int> &A, const vector<int> &B) {
    vector<int> ans;
    
    int i = 0;
    int j = 0;
    
    while(i<A.size() && j<B.size()) {
        
        if(A[i] == B[j]) {
            ans.push_back(A[i]);
            i++;
            j++;
        }
        else if(A[i] > B[j])
            j++;
        else
            i++;        
    }
    
    return ans;
}
