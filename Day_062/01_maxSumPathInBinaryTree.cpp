// Question Link: https://www.interviewbit.com/problems/max-sum-path-in-binary-tree/

/*
Max Sum Path in Binary Tree

Problem Description:
Given a binary tree T, find the maximum path sum.

The path may start and end at any node in the tree.

Problem Constraints:
1 <= Number of Nodes <= 7e4
-1000 <= Value of Node in T <= 1000

Input Format:
 The first and the only argument contains a pointer to the root of T, A.

Output Format:
Return an integer representing the maximum sum path.

Example Input:
Input 1:
    1
   / \
  2   3
Input 2:
       20
      /  \
   -10   20
        /  \
      -10  -50

Example Output:
Output 1:
 6
Output 2:
 40

Example Explanation:
Explanation 1:
     The path with maximum sum is: 2 -> 1 -> 3
Explanation 2:
     The path with maximum sum is: 20 -> 20
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
int sum(TreeNode* root, int &ans){
    if(root == NULL)
        return 0;

    int lh = max(0, sum(root->left,ans));
    int rh = max(0, sum(root->right,ans));

    ans =  max(ans, root->val + lh+rh);

    return root->val + max(lh, rh);
}

int Solution::maxPathSum(TreeNode* root) {
    int ans = INT_MIN/2;
    sum(root, ans);

    return ans;
}
