// Question Link: https://www.interviewbit.com/problems/reverse-level-order/

/*
Reverse Level Order

Problem Description:
Given a binary tree, return the reverse level order traversal of its nodes values. (i.e, from left to right and from last level to starting level).

Problem Constraints:
1 <= number of nodes <= 5 * 10^5
1 <= node value <= 10^5

Input Format:
First and only argument is a pointer to the root node of the Binary Tree, A.

Output Format:
Return an integer array denoting the reverse level order traversal from left to right.

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
 [15, 7, 9, 20, 3] 
Output 2:
 [3, 6, 2, 1]

Example Explanation:
Explanation 1:
 Nodes as level 3 : [15, 7]
 Nodes at level 2: [9, 20]
 Nodes at level 1: [3]
 Reverse level order traversal will be: [15, 7, 9, 20, 3]
Explanation 2:
 Nodes as level 3 : [3]
 Nodes at level 2: [6, 2]
 Nodes at level 1: [1]
 Reverse level order traversal will be: [3, 6, 2, 1]
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
vector<int> Solution::solve(TreeNode* A) {
    TreeNode *head=A;
    queue<TreeNode*>q;
    q.push(head);
    vector<int>ans;
   
    while(q.empty()==false){
        TreeNode *temp=q.front();
        ans.push_back(temp->val);
        q.pop();
        if(temp->right!=NULL){
            q.push(temp->right);
        }
        if(temp->left!=NULL){
            q.push(temp->left);
        }
    }
    reverse(ans.begin(),ans.end());
    return ans;
}
