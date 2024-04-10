// Question Link: https://www.interviewbit.com/problems/convert-sorted-list-to-binary-search-tree/

/*
Convert Sorted List to Binary Search Tree

Given a singly linked list where elements are sorted in ascending order, convert it to a height balanced BST.
A height balanced BST : a height-balanced binary tree is defined as a binary tree in which the depth of the two subtrees of every node never differ by more than 1.

Example :
Given A : 1 -> 2 -> 3
A height balanced BST  :

      2
    /   \
   1     3
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
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
TreeNode* func(vector<int>&  lv, int l, int r){
      int n = lv.size();
      if(l<0 or r>=n or r<l) return NULL;
       int mid =  l+(r-l)/2;
        TreeNode* node = new TreeNode(lv[mid]);
        node->left = func(lv,l,mid-1);
        node->right= func(lv, mid+1,r);
        return node;
  }
 
TreeNode* Solution::sortedListToBST(ListNode* A) {
    vector<int> lv;
    while(A) {
        lv.push_back(A->val);
        A = A->next;
    }
    TreeNode* node = func(lv,0, lv.size()-1);
    return node;
}
