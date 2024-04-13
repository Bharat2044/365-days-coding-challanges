// Question Link: https://www.interviewbit.com/problems/binary-tree-from-inorder-and-postorder/

/*
Binary Tree From Inorder And Postorder

Given inorder and postorder traversal of a tree, construct the binary tree.

Note: You may assume that duplicates do not exist in the tree.

Example :
Input : 
        Inorder : [2, 1, 3]
        Postorder : [2, 3, 1]

Return : 
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
 TreeNode* buildBinaryTree(vector<int>& inorder,int instart,int inend, vector<int>& postorder,int poststart,int postend,map<int,int>&mp){
    if(instart>inend || poststart>postend) 
        return NULL;
    
    TreeNode* root = new TreeNode(postorder[postend]);
    int inroot = mp[postorder[postend]];
    int num = inroot-instart;
    
    root->left = buildBinaryTree(inorder,instart,inroot-1,postorder,poststart,poststart+num-1,mp);
    root->right = buildBinaryTree(inorder,inroot+1,inend,postorder,poststart+num,postend-1,mp);
    
    return root;
}
    
TreeNode* Solution::buildTree(vector<int> &inorder, vector<int> &postorder) {
    map<int,int>mp;
    
    for(int i=0;i<inorder.size();i++){
        mp[inorder[i]] = i;
    }
    return buildBinaryTree(inorder,0,inorder.size()-1,postorder,0,postorder.size()-1,mp);
}
