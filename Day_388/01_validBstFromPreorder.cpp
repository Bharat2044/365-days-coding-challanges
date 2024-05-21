// Question Link: https://www.interviewbit.com/problems/valid-bst-from-preorder/

/*
Valid BST from Preorder

Problem Description:
You are given a preorder traversal A, of a Binary Search Tree.
Find if it is a valid preorder traversal of a BST.
Note: Binary Search Tree by definition has distinct keys and duplicates in binary search tree are not allowed.

Problem Constraints:
1 <= A[i] <= 10^6
1 <= |A| <= 10^5

Input Format:
First and only argument is an integer array A denoting the pre-order traversal.

Output Format:
Return an integer:
0 : Impossible preorder traversal of a BST
1 : Possible preorder traversal of a BST

Example Input:
Input 1:
A = [7, 7, 10, 10, 9, 5, 2, 8]

Example Output:
Output 1:
 0
Show similar questions
*/



int Solution::solve(vector<int> &arr) {
    int n = arr.size();
    for(int i=1;i<n;i++)
    {
         if(arr[i]==arr[i-1])  return 0;
    }
    stack<int> st;
    int root = INT_MIN;
    for(int i=0;i<n;i++)
    {
        while(!st.empty() && arr[i] > st.top())
        {
            root = st.top();
            st.pop();
        }
        if(arr[i] < root) return 0;
        st.push(arr[i]);
    }
    return 1;
}
