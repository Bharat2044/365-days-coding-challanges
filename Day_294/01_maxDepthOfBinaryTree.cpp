// Question Link: https://www.interviewbit.com/problems/max-depth-of-binary-tree/

/*
Max Depth of Binary Tree

Given a binary tree, find its maximum depth.
The maximum depth of a binary tree is the number of nodes along the longest path from the root node down to the farthest leaf node.

NOTE : The path has to end on a leaf node.

Example :
         1
        /
       2
max depth = 2.
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
int Solution::maxDepth(TreeNode* A) {
    queue<TreeNode*> ds;
    ds.push(A);
    vector<vector<int>>res;
    vector<int>ans;
    TreeNode* temp;
    while (!ds.empty()){
        int size=ds.size();
       
        for (int i=0;i<size;i++){
            temp=ds.front();
            ds.pop();
            ans.push_back(temp->val);
            if (temp->left!=NULL){
                ds.push(temp->left);
            }
            if (temp->right!=NULL){
                ds.push(temp->right);
            }
        }
        res.push_back(ans);
       
    }
   
    return res.size();
}
