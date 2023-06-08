// Question Link: https://www.interviewbit.com/problems/unique-binary-search-trees/

/*
Unique Binary Search Trees

Problem Description:
Given A, generate all structurally unique BST's (binary search trees) that store values 1...A.

Problem Constraints:
1 <= A <= 15

Input Format:
The first argument is an integer A.

Output Format:
Return an array of TreeNode

Example Input:
A = 3

Example Output:
   1         3     3      2      1
    \       /     /      / \      \
     3     2     1      1   3      2
    /     /       \                 \
   2     1         2                 3
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

 vector<TreeNode*> solve(int s,int e) {
    vector<TreeNode*> ans;

    if(s > e)
        return {NULL};

    for(int i=s;i<=e;i++) {
        vector<TreeNode*> leftsubtree=solve(s,i-1);
        vector<TreeNode*> rightsubtree=solve(i+1,e);         

        for(auto l : leftsubtree){
            for(auto r : rightsubtree) {
                
                TreeNode* newroot = new TreeNode(i);
                newroot->left = l;
                newroot->right = r;              
                ans.push_back(newroot);
            }
        }
    }
     
    return ans;
 }

vector<TreeNode*> Solution::generateTrees(int A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details

    return solve(1,A);
}
