// Question Link: https://www.interviewbit.com/problems/sum-root-to-leaf-numbers/

/*
Sum Root to Leaf Numbers

Problem Description:
Given a binary tree containing digits from 0-9 only, each root-to-leaf path could represent a number.
An example is the root-to-leaf path 1->2->3 which represents the number 123.
Find the total sum of all root-to-leaf numbers % 1003.

Problem Constraints:
0 <= Node.val <= 9

Input Format:
The first argument is TreeNode A, pointing to the root of the tree.

Output Format:
Return an integer equal to the total sum of all root-to-leaf numbers % 1003.

Example Input
    1
   / \
  2   3

Example Output:
25

Example Explanation:
    1
   / \
  2   3
The root-to-leaf path 1->2 represents the number 12.
The root-to-leaf path 1->3 represents the number 13.

Return the sum = (12 + 13) % 1003 = 25 % 1003 = 25.
*/



int Solution::sumNumbers(TreeNode* A) {
    int sum = 0;
   
    if(A==NULL){
        return 0;
    }
    vector<int> v;
   
    queue<pair<TreeNode*, int>> q;
    q.push({A, A->val});
   
    while(q.empty()==false){
       
        int count = q.size();
       
        for(int i=0; i<count; i++){
            auto curr = q.front();
            q.pop();
           
            if(curr.first->left == NULL && curr.first->right == NULL){
                v.push_back(curr.second);
            }
           
            if(curr.first->left !=NULL){
                q.push({curr.first->left, (curr.second*10 + curr.first->left->val)%1003});
            }
            if(curr.first->right != NULL){
                q.push({curr.first->right, (curr.second*10 + curr.first->right->val)%1003});
            }
        }  
       
    }
   
    for(int i=0; i<v.size(); i++){
        sum += v[i];
    }
   
    return sum  % 1003;
}
