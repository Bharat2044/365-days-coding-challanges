// Question Link: https://interviewbit.com/problems/burn-a-tree/

/*
Burn a Tree

Problem Description:
Given a binary tree denoted by root node A and a leaf node B from this tree.
It is known that all nodes connected to a given node (left child, right child and parent) get burned in 1 second. Then all the nodes which are connected through one intermediate get burned in 2 seconds, and so on.
You need to find the minimum time required to burn the complete binary tree.

Problem Constraints:
2 <= number of nodes <= 10^5
1 <= node value, B <= 10^5
node value will be distinct

Input Format:
First argument is a root node of the binary tree, A.
Second argument is an integer B denoting the node value of leaf node.

Output Format:
Return an integer denoting the minimum time required to burn the complete binary tree.

Example Input:
Input 1:
 Tree :      1 
            / \ 
           2   3 
          /   / \
         4   5   6
 B = 4
Input 2:
 Tree :      1
            / \
           2   3
          /     \
        4       5 
 B = 5 
 
Example Output:
Output 1:
 4
Output 2:
 4

Example Explanation:
Explanation 1:
 After 1 sec: Node 4 and 2 will be burnt. 
 After 2 sec: Node 4, 2, 1 will be burnt.
 After 3 sec: Node 4, 2, 1, 3 will be burnt.
 After 4 sec: Node 4, 2, 1, 3, 5, 6(whole tree) will be burnt.
Explanation 2:
 After 1 sec: Node 5 and 3 will be burnt. 
 After 2 sec: Node 5, 3, 1 will be burnt.
 After 3 sec: Node 5, 3, 1, 2 will be burnt.
 After 4 sec: Node 5, 3, 1, 2, 4(whole tree) will be burnt.
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
void findheight(TreeNode* root,unordered_map<int,vector<int>> &adj,int parent){
     if(root==NULL)return;
     if(parent!=-1){
         adj[parent].push_back(root->val);
         adj[root->val].push_back(parent);
     }
     findheight(root->left,adj,root->val);
     findheight(root->right,adj,root->val);
     return;
 }
int Solution::solve(TreeNode* A, int B) {
    unordered_map<int,vector<int>> adj;
    findheight(A,adj,-1);
    unordered_map<int,int> vis;
    queue<pair<int,int>> q;
    q.push({B,0});
    int ans=0;
    while(!q.empty()){
        int node=q.front().first;
        int lvl=q.front().second;
        ans=max(lvl,ans);
        q.pop();
        vis[node]=1;
        for(auto it:adj[node]){
            if(!vis[it]){
                q.push({it,lvl+1});
                vis[it]=1;
            }
        }
    }
    return ans;
}
