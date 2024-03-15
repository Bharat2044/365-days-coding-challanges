// Question Link: https://www.interviewbit.com/problems/zigzag-level-order-traversal-bt/

/*
ZigZag Level Order Traversal BT

Given a binary tree, return the zigzag level order traversal of its nodes’ values. (ie, from left to right, then right to left for the next level and alternate between).

Example : 
Given binary tree
    3
   / \
  9  20
    /  \
   15   7
return
[
         [3],
         [20, 9],
         [15, 7]
]
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
vector<vector<int> > Solution::zigzagLevelOrder(TreeNode* A)
{
    vector<vector<int>> result;
    if(A==NULL) return result;
    queue<TreeNode*> nodequeue;
    nodequeue.push(A);
    bool  ltor=true;//left to right ltor
    while(!nodequeue.empty())
    {
        int size=nodequeue.size();
        vector<int>row(size);
        for(int i=0;i<size;i++)
        {
            TreeNode* node=nodequeue.front();
            nodequeue.pop();
            int index=ltor?i:(size-1-i);
            row[index]=node->val;
            if(node->left)
            {
                nodequeue.push(node->left);
            }
           
            if(node->right)
            {
                nodequeue.push(node->right);
            }
        }
        ltor=!ltor;
        result.push_back(row);
       
    }
    return result;
}
