// Question Link: https://www.interviewbit.com/problems/inorder-traversal-of-cartesian-tree/

/*
Inorder Traversal of Cartesian Tree

Given an inorder traversal of a cartesian tree, construct the tree.
Cartesian tree :  is a heap ordered binary tree, where the root is greater than all the elements in the subtree.
Note: You may assume that duplicates do not exist in the tree.

Example :
Input : [1 2 3]
Return :   
          3
         /
        2
       /
      1
*/



TreeNode* Solution::buildTree(vector<int> &A) {
    stack<TreeNode*> s;

    TreeNode* root = nullptr;

    for (int num : A) {
        TreeNode* curr = new TreeNode(num);
        while (!s.empty() && s.top()->val < num) {
            curr->left = s.top();
            s.pop();
        }
        if (s.empty()) {
            root = curr;
        } else {
            s.top()->right = curr;
        }
        s.push(curr);
    }

    return root;
}
