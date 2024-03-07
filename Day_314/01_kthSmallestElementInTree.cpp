// Question Link: https://www.interviewbit.com/problems/kth-smallest-element-in-tree/

/*
Kth Smallest Element In Tree

Problem Description:
Given a binary search tree, write a function to find the kth smallest element in the tree.
NOTE: You may assume 1 <= k <= Total number of nodes in BST

Input Format:
The first argument is the root node of the binary tree.
The second argument B is an integer equal to the value of k.

Output Format:
Return the value of the kth smallest node.

Example Input:
  2
 / \
1   3
and k = 2

Example Output:
2

Example Explanation:
As 2 is the second smallest element in the tree.
*/



/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 int solve(TreeNode* root, priority_queue<int>&pq, int B){
     if(root==NULL){
        return pq.top();    
     }
     
     pq.push(root->val);
     
     if(pq.size()>B)
        pq.pop();
        
     int a = solve(root->left, pq, B);
     int b = solve(root->right, pq, B);
     
     return pq.top();
 }
 
int Solution::kthsmallest(TreeNode* A, int B) {
    priority_queue<int>pq;
    
    return solve(A, pq, B);
}
