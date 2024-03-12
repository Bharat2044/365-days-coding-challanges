// Question Link: https://www.interviewbit.com/problems/populate-next-right-pointers-tree/

/*
Populate Next Right Pointers Tree

Problem Description:
Given a binary tree
    struct TreeLinkNode {
      TreeLinkNode *left;
      TreeLinkNode *right;
      TreeLinkNode *next;
    } 
Populate each next pointer to point to its next right node. If there is no next right node, the next pointer should be set to NULL.
Initially, all next pointers are set to NULL.

NOTE:
You may only use constant extra space.
Recursion has memory overhead and does not qualify for constant space.
The tree need not be a perfect binary tree.

Input Format:
The first argument is TreeNode A, pointing to the root of the tree.

Output Format:
Update the given TreeNode A.

Example Input:
         1
       /  \
      2    3
     / \  / \
    4  5  6  7

Example Output:
         1 -> NULL
       /  \
      2 -> 3 -> NULL
     / \  / \
    4->5->6->7 -> NULL
*/




/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
void Solution::connect(TreeLinkNode* A) {
    queue<TreeLinkNode*>q;
    q.push(A);
    while(!q.empty()){
        int sz=q.size();
        for(int i=0;i<sz;i++){
            TreeLinkNode*temp=q.front();
            q.pop();
            if(i<=sz-2){
                temp->next=q.front();
            }
            if(i==sz-1)temp->next=NULL;
            if(temp->left)q.push(temp->left);
            if(temp->right)q.push(temp->right);
        }
    }
}
