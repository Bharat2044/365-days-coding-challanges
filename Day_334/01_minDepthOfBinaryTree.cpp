// Question Link: https://www.interviewbit.com/problems/min-depth-of-binary-tree/

/*
Min Depth of Binary Tree

Problem Description:
Given a binary tree, find its minimum depth.
The minimum depth is the number of nodes along the shortest path from the root node down to the nearest leaf node.
NOTE: The path has to end on a leaf node.

Input Format:
The first argument is a TreeNode, pointing to the root of the binary tree.

Output Format:
Return an integer equal to the minimum depth of the tree.

Example Input:
  1
 /
2

Example Output:
2

Example Explanation:
Minimum Depth is 2, which is from 1 -> 2.
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
int Solution::minDepth(TreeNode* A) {
    if(A==NULL) {
        return 0;
    }
    
    int l=minDepth(A->left);
    int r=minDepth(A->right);
    
    if(!l||!r) {
        return max(l,r)+1;
    }
    
    return (1+min(l,r));
}
