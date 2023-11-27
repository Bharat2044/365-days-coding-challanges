// Question Link: https://www.interviewbit.com/problems/preorder-traversal/

/*
Preorder Traversal

Given a binary tree, return the preorder traversal of its nodes’ values.

Example :
Given binary tree
   1
    \
     2
    /
   3
return [1,2,3].

Using recursion is not allowed.
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
vector<int> Solution::preorderTraversal(TreeNode* root)
{   
    vector<int>v;
    if(root==NULL)
        return v;
        
    stack<TreeNode*>s;
    s.push(root);
    
    while(s.empty()==false)
    {
        TreeNode* curr=s.top();
        v.push_back(curr->val);
        s.pop();
       
        if(curr->right!=NULL)
        {
            s.push(curr->right);
        }
        if(curr->left!=NULL)
        {
            s.push(curr->left);
        }
    }

    return v;
}

