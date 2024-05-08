// Question Link: https://www.interviewbit.com/problems/cousins-in-binary-tree/

/*
Cousins in Binary Tree

Problem Description:
Given a Binary Tree A consisting of N nodes.
You need to find all the cousins of node B.

NOTE:
Siblings should not be considered as cousins.
Try to do it in single traversal.
You can assume that Node B is there in the tree A.
Order doesn't matter in the output.

Problem Constraints:
 1 <= N <= 10^5 
 1 <= B <= N

Input Format:
First Argument represents the root of binary tree A.
Second Argument is an integer B denoting the node number.

Output Format:
Return an integer array denoting the cousins of node B.

NOTE: Order doesn't matter.

Example Input:
Input 1:
 A =
           1
         /   \
        2     3
       / \   / \
      4   5 6   7 
B = 5
Input 2:
 A = 
            1
          /   \
         2     3
        / \ .   \
       4   5 .   6
B = 1

Example Output:
Output 1:
 [6, 7]
Output 2:
 []

Example Explanation:
Explanation 1:
 Cousins of Node 5 are Node 6 and 7 so we will return [6, 7]
 Remember Node 4 is sibling of Node 5 and do not need to return this.
Explanation 2:
 Since Node 1 is the root so it doesn't have any cousin so we will return an empty array.
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
vector<int> Solution::solve(TreeNode* A, int B) {
    vector<int> ans;
    queue<TreeNode*> q;
    q.push(A);
    
    while(q.size()){
        int n = q.size();
        vector<pair<int,int>> v;
        
        for(int i=0; i<n; i++){
            TreeNode* t = q.front();
            q.pop();
            
            if(t->left) { q.push(t->left); v.push_back({t->left->val, t->val});}
            if(t->right) { q.push(t->right); v.push_back({t->right->val, t->val});}
        }
        
        int p=-1;
        
        for(auto i : v){
            if(i.first==B) {p=i.second; break;}
        }
        
        if(p!=-1) {
            for(auto i : v){
                if(i.second!=p)
                    ans.push_back(i.first);
            }
        
            return ans;
        }
    }
    
    return ans;
}
