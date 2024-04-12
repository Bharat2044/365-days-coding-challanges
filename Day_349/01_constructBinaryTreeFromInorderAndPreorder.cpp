// Question Link: https://www.interviewbit.com/problems/construct-binary-tree-from-inorder-and-preorder/

/*
Construct Binary Tree From Inorder And Preorder

Problem Description:
Given preorder and inorder traversal of a tree, construct the binary tree.
Note: You may assume that duplicates do not exist in the tree.

Problem Constraints:
1 <= |A| <= 10^5
|A| == |B|

Input Format:
The first argument is an integer array A representing the preorder traversal.
The second argument is an integer array B representing the inorder traversal.

Output Format:
Return the pointer to the root node of the tree.

Example Input:
Preorder : [1, 2, 3]
Inorder  : [2, 1, 3]

Example Output
            1
           / \
          2   3
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
int ind=0;
TreeNode* build(vector <int> &A,vector<int>&B,int s,int e){
    int idx=-1;
    
    for(int i=s; i<=e; i++){
        if(B[i] == A[ind]){
            idx = i;
            ind++;
            break;
        }
    }
    
    if(idx==-1)
        return NULL;
    
    TreeNode* root = new TreeNode(B[idx]);
    root->left = build(A,B,s,idx-1);
    root->right = build(A,B,idx+1,e);

    return root;
}

TreeNode* Solution::buildTree(vector<int> &A, vector<int> &B) {
    ind=0;
    
    return build(A,B,0,B.size()-1);
}
