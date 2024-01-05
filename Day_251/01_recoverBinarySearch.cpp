// Question Link: https://www.interviewbit.com/problems/recover-binary-search-tree/

/*
Recover Binary Search Tree

Two elements of a binary search tree (BST) are swapped by mistake.
Tell us the 2 values swapping which the tree will be restored.

Note:
A solution using O(n) space is pretty straight forward. Could you devise a constant space solution?

Example :
Input : 
         1
        / \
       2   3
Output : 
       [1, 2]
Explanation : Swapping 1 and 2 will change the BST to be 
         2
        / \
       1   3
which is a valid BST          
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
void solve(TreeNode* A, vector<int>& res, int& minVal){
    if(!A){
        return;
    }
    solve(A->right, res, minVal);
    minVal = min(minVal, A->val);
    if(A->val > minVal){
        res[0] = minVal;
        res[1] = A->val;
    }
    solve(A->left, res, minVal);
}

vector<int> Solution::recoverTree(TreeNode* A){
    vector<int> res(2, 0);
    int minVal = INT_MAX;
    solve(A, res, minVal);
    return res;
}
