// Question Link: https://www.interviewbit.com/problems/next-pointer-binary-tree/

/*
Next Pointer Binary Tree

Given a binary tree
    struct TreeLinkNode {
      TreeLinkNode *left;
      TreeLinkNode *right;
      TreeLinkNode *next;
    }
Populate each next pointer to point to its next right node. If there is no next right node, the next pointer should be set to NULL.
Initially, all next pointers are set to NULL.

Note:
You may only use constant extra space.
You may assume that it is a perfect binary tree (ie, all leaves are at the same level, and every parent has two children).

Example :
Given the following perfect binary tree,
         1
       /  \
      2    5
     / \  / \
    3  4  6  7
After calling your function, the tree should look like:
         1 -> NULL
       /  \
      2 -> 5 -> NULL
     / \  / \
    3->4->6->7 -> NULL
Note that using recursion has memory overhead and does not qualify for constant space.
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
    TreeLinkNode* prev;
    queue<TreeLinkNode*>q;
    q.push(A);
    while(q.size()>0){
        int sz=q.size();
        prev=NULL;
        for(int i=0;i<sz;i++){
            TreeLinkNode* temp=q.front();
            q.pop();
            if(prev==NULL){
                prev=temp;
            }
            else{
                prev->next=temp;
                prev=temp;
            }
            if(temp->left){
                q.push(temp->left);
            }
            if(temp->right){
                q.push(temp->right);
            }
        }
        prev->next=NULL;
    }
}
