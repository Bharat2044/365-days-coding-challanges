// Question Link: https://www.interviewbit.com/problems/level-order/

/*
Level Order

Problem Description:
Given a binary tree, return the level order traversal of its nodes' values. (ie, from left to right, level by level).

Problem Constraints:
 1 <= number of nodes <= 105

Input Format:
First and only argument is root node of the binary tree, A.

Output Format:
Return a 2D integer array denoting the zigzag level order traversal of the given binary tree.

Example Input:
Input 1:
    3
   / \
  9  20
    /  \
   15   7
Input 2:
   1
  / \
 6   2
    /
   3

Example Output:
Output 1:
 [
   [3],
   [9, 20],
   [15, 7]
 ]
Output 2:
 [ 
   [1]
   [6, 2]
   [3]
 ]

Example Explanation:
Explanation 1:
 Return the 2D array. Each row denotes the traversal of each level.
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
vector<vector<int> > Solution::levelOrder(TreeNode* A)
{
    vector<vector<int>>ans;
    vector<int> temp;
    queue<TreeNode*> q;
    q.push(A);
    q.push(NULL);
    while(q.size())
    {
        if(q.front()==NULL)
        {
            q.pop();
            ans.push_back(temp);
            temp.clear();
            if(q.size())
            {
                q.push(NULL);
            }
            else
            break;
        }
       
        TreeNode* root=q.front();
        q.pop();
       
       int root_val=root->val;
       
        temp.push_back(root_val);
       
        if(root->left)
        {
            q.push(root->left);
        }
        if(root->right)
        {
            q.push(root->right);
        }
    }
    return ans;
}
