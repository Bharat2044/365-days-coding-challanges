// Question Link: https://www.interviewbit.com/problems/sort-array-with-squares/

/*
Sort array with squares!

Problem Description:
Given a sorted array A containing N integers both positive and negative.
You need to create another array containing the squares of all the elements in A and return it in non-decreasing order.
Try to this in O(N) time.

Problem Constraints:
1 <= N <= 105.
-103 <= A[i] <= 103

Input Format:
First and only argument is an integer array A.

Output Format:
Return a integer array as described in the problem above.

Example Input:
Input 1:
 A = [-6, -3, -1, 2, 4, 5]
Input 2:
 A = [-5, -4, -2, 0, 1]

Example Output:
Output 1:
 [1, 4, 9, 16, 25, 36]
Output 2:
 [0, 1, 4, 16, 25]
*/



vector<int> Solution::solve(vector<int> &A) {
    multiset<int> st;
    int n=A.size();
    
    for(int i=0;i<n;i++)
        st.insert(A[i]*A[i]);
    
    vector<int> vect(n);
    int i=0;
    
    for(auto x:st){
      vect[i++] = x;
    }
      
    return vect;
}
