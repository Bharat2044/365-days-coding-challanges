// Question Link: https://www.interviewbit.com/problems/maximum-level-sum/

/*
Maximum level sum

Problem Description:
Given a Binary Tree denoted by root node A having integer value on nodes. You need to find maximum sum level in it.

Problem Constraints:
1 <= number of nodes <= 10^5
1 <= value on nodes <= 10^5

Input Format:
First and only argument is a root node of Binary Tree A.

Output Format:
Return an integer denoting the maximum sum level in the tree.

Example Input:
Input 1:
 Tree:      4
          /   \
         2     5
        / \   / \
       1  3  2   6
Input 2:
 Tree:      1
          /   \
         2     3
       /  \     \
      4    5     8
                / \
               6   7  
               
Example Output:
Output 1:
 12
Output 2:
 17

Example Explanation:
Explanation 1:
 Sum of all nodes of 0'th level is 4 
 Sum of all nodes of 1'th level is 7
 Sum of all nodes of 2'th level is 12
 Hence maximum sum is 12
Explanation 2:
 Sum of all nodes of 0'th level is 1
 Sum of all nodes of 1'th level is 5
 Sum of all nodes of 2'th level is 17
 Sum of all nodes of 3'th level is 13
 Hence maximum sum is 17
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
int bfs(TreeNode* root)
{
    int max_sum=-1;
    int sum=0;
    queue<TreeNode*> q;
    
    q.push(root);
    int size=1;
    
    while(!q.empty())
    {
        auto curr=q.front(); 
        q.pop();
        sum+=curr->val;
        
        if(curr->left)
            q.push(curr->left);
            
        if(curr->right)
            q.push(curr->right);
        size--;
        
        if(size==0)
        {
            size=q.size();
            max_sum=max(sum,max_sum);
            sum=0;
        }
    }
        
    return max_sum;
}

int Solution::solve(TreeNode* A) {
    if(A==nullptr)
        return 0;
        
    return bfs(A);
}
