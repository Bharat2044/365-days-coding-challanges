// Question Link: https://www.interviewbit.com/problems/remove-half-nodes/

/*
Remove Half Nodes

Problem Description:
Given a binary tree A with N nodes.
You have to remove all the half nodes and return the final binary tree.

NOTE:
Half nodes are nodes which have only one child.
Leaves should not be touched as they have both children as NULL.

Problem Constraints:
 1 <= N <= 10^5

Input Format:
First and only argument is an pointer to the root of binary tree A.

Output Format:
Return a pointer to the root of the new binary tree.

Example Input:
Input 1:
           1
         /   \
        2     3
       / 
      4
Input 2:
            1
          /   \
         2     3
        / \     \
       4   5     6

Example Output:
Output 1:
           1
         /   \
        4     3
Output 2:
            1
          /   \
         2     6
        / \
       4   5

Example Explanation:
Explanation 1:
 The only half node present in the tree is 2 so we will remove this node.
Explanation 2:
 The only half node present in the tree is 3 so we will remove this node.
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

void removeHalfChild(TreeNode* &root){
    if(root == NULL) return;

    if(root->left != NULL && root->right == NULL) root = root->left;
    if(root->right != NULL && root->left == NULL) root = root->right;

    removeHalfChild(root->left);
    removeHalfChild(root->right);
}

TreeNode* Solution::solve(TreeNode* A) {
    removeHalfChild(A);

    return A;
}
