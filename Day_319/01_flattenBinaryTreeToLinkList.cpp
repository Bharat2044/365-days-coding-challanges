// Question Link: https://www.interviewbit.com/problems/flatten-binary-tree-to-linked-list/

/*
Flatten Binary Tree to Linked List

Problem Description:
Given a binary tree A, flatten it to a linked list in-place.
The left child of all nodes should be NULL.

Problem Constraints:
1 <= size of tree <= 100000

Input Format:
First and only argument is the head of tree A.

Output Format:
Return the linked-list after flattening.

Example Input:
Input 1:
     1
    / \
   2   3
Input 2:
         1
        / \
       2   5
      / \   \
     3   4   6

Example Output:
Output 1:
1
 \
  2
   \
    3
Output 2:
1
 \
  2
   \
    3
     \
      4
       \
        5
         \
          6

Example Explanation:
Explanation 1:
Tree flattening looks like this.
Explanation 2:
Tree flattening looks like this.
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
TreeNode* Solution::flatten(TreeNode* A) {
    if (A == NULL) 
        return A;

    TreeNode * s = new TreeNode(A->val);
    TreeNode * k = s;
    stack<TreeNode *>  q;

    if (A->right) 
        q.push(A->right);

    if (A->left) 
        q.push(A->left);

    while(!q.empty()){
        TreeNode * temp = q.top();

        s->right = temp;
        s->left = NULL;

        s = s->right;
        q.pop();

        if (temp->right != NULL) 
            q.push(temp->right);

        if (temp->left != NULL) 
            q.push(temp->left);
    }

    return k;
}



