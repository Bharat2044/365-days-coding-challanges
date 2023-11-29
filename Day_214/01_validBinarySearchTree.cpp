Question Link: https://www.interviewbit.com/problems/valid-binary-search-tree/

/*
Valid Binary Search Tree

Given a binary tree, determine if it is a valid binary search tree (BST).

Assume a BST is defined as follows:

The left subtree of a node contains only nodes with keys less than the node’s key.
The right subtree of a node contains only nodes with keys greater than the node’s key.
Both the left and right subtrees must also be binary search trees.

Example :
Input : 
   1
  /  \
 2    3

Output : 0 (False)

Input : 
  2
 / \
1   3

Output : 1 (True) 
Return 0 / 1 ( 0 for false, 1 for true ) for this problem
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
bool isBSTUtil(TreeNode *root, int minVal, int maxVal){
    if(root == NULL) 
        return true;
     
    if(root->val > minVal && root->val < maxVal && isBSTUtil(root->left, minVal, root->val) && isBSTUtil(root->right, root->val, maxVal))
        return true;
    else 
        return false;
}
 
int Solution::isValidBST(TreeNode* A) {
    return isBSTUtil(A, INT_MIN, INT_MAX);
}
