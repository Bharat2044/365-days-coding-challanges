// Question Link: https://www.interviewbit.com/problems/next-greater-number-bst/

/*
Next Greater Number BST

Given a BST node, return the node which has value just greater than the given node.

Example:
Given the tree
               100
              /   \
            98    102
           /  \
         96    99
          \
           97
Given 97, you should return the node corresponding to 98 as thats the value just greater than 97 in the tree.
If there are no successor in the tree ( the value is the largest in the tree, return NULL).
Using recursion is not allowed.
Assume that the value is always present in the tree.

PROBLEM APPROACH:
Complete solution in the hint.
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
TreeNode* Solution::getSuccessor(TreeNode* A, int B) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details

    TreeNode* successor = nullptr;
   
    while (A) {
        if (A->val <= B) {
            A = A->right; // Move to the right subtree
        } else {
            successor = A; // Current node could be a successor
            A = A->left;  // Move to the left subtree
        }
    }
   
    return successor;
}
