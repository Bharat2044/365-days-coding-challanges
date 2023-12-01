// Question Link: https://www.interviewbit.com/problems/postorder-traversal/

/*
Postorder Traversal

Problem Description:
Given a binary tree, return the Postorder traversal of its nodes values.

NOTE: Using recursion is not allowed.

Problem Constraints:
1 <= number of nodes <= 105

Input Format:
First and only argument is root node of the binary tree, A.

Output Format:
Return an integer array denoting the Postorder traversal of the given binary tree.

Example Input:
Input 1:
   1
    \
     2
    /
   3
Input 2:
   1
  / \
 6   2
    /
   3

Example Output:
Output 1:
 [3, 2, 1]
Output 2:
 [6, 3, 2, 1]

Example Explanation:
Explanation 1:
The Preoder Traversal of the given tree is [3, 2, 1].
Explanation 2:
The Preoder Traversal of the given tree is [6, 3, 2, 1].
*/


void post(TreeNode* root,vector<int>&res)
    {  if(!root)return;
       
    post(root->left,res);
   post(root->right,res);
    res.push_back(root->val);
       
    }
vector<int> Solution::postorderTraversal(TreeNode* A) {
    vector<int>res;
   
    post(A,res);
   
    return res;
}
