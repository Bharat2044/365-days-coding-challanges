// Question Link: https://leetcode.com/problems/binary-tree-paths/

/*
257. Binary Tree Paths

Given the root of a binary tree, return all root-to-leaf paths in any order.

A leaf is a node with no children.

Example 1:
Input: root = [1,2,3,null,5]
Output: ["1->2->5","1->3"]
Example 2:
Input: root = [1]
Output: ["1"]

Constraints:
The number of nodes in the tree is in the range [1, 100].
-100 <= Node.val <= 100
*/



/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector <string> res; //store result

    void addToPath(int val, string &path){
        path += "->" + to_string(val);
    }

    void removeFromPath(int val, string &path){
        int len = to_string(val).length() + 2; // +2 due to "->"
        while(len--) path.pop_back(); 
    }

    void traverse(TreeNode* root, string &path){
        if(!root) return;
        if(!root->left && !root->right){ //reached leaf node
            addToPath(root->val, path); //do
            res.push_back(path); //add path 
            removeFromPath(root->val, path); //undo
            return;
        }

        addToPath(root->val, path); //do
        traverse(root->left, path); //recurse
        traverse(root->right, path);
        removeFromPath(root->val, path); //undo 
    }

    vector<string> binaryTreePaths(TreeNode* root) {
        res.clear(); // clear result first
        string path = to_string(root->val); // initialise path with root
        if(!root->left && !root->right) return {path};
        //check wether head itself is not a root if yes then return head value as only path

        traverse(root->left, path); //recurse left subtree
        traverse(root->right, path); //recurse right subtree
        return res;

    }
};
