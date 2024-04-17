// Question Link: https://www.interviewbit.com/problems/ways-to-form-max-heap/

/*
Ways to form Max Heap

Problem Description:
Max Heap is a special kind of complete binary tree in which for every node the value present in that node is greater than the value present in it’s children nodes.
Find the number of distinct Max Heap can be made from A distinct integers.

In short, you have to ensure the following properties for the max heap :
Heap has to be a complete binary tree ( A complete binary tree is a binary tree in which every level, except possibly the last, is completely filled, and all nodes are as far left as possible.)
Every node is greater than all its children.
NOTE:  If you want to know more about Heaps, please visit this link. Return your answer modulo 10^9 + 7.

Problem Constraints:
1 <= A <= 100

Input Format:
First and only argument is an integer A.

Output Format:
Return an integer denoting the number of distinct Max Heap.

Example Input:
Input 1:
 A = 4
Input 2:
 A = 10

Example Output:
Output 1:
 3
Output 2:
 3360

Example Explanation:
Explanation 1:
 Let us take 1, 2, 3, 4 as our 4 distinct integers
 Following are the 3 possible max heaps from these 4 numbers :
      4           4                     4
    /  \         / \                   / \ 
   3    2   ,   2   3      and        3   1
  /            /                     /

 1            1                     2
Explanation 2:
 Number of distinct heaps possible with 10 distinct integers = 3360.
*/



#define MOD ((int)1e9 + 7)
#define ll long long

int Solution::solve(int n) {
    ll ans[n + 1] = {0};
    memset(ans, 0, sizeof(ans));
    ll c[n][n];
    memset(c, 0, sizeof(c));
    
    for(int i = 0; i <= n; i++){
        for(int j = 0; j <= i; j++){
            if(i == j || j == 0){c[i][j] = 1;continue;}
            c[i][j] = (c[i-1][j] + c[i-1][j-1])%MOD;
        }
    }
    ans[0] = 1;
    for(int i = 1; i <= n; i++){
        ll total_nodes = 0; // all the nodes assuming perfect and complete binary tree
        ll level = 1;
        ll complete_nodes = 0; // all the nodes with full levels
        ll current_nodes = i - 1; // leaving the top element, as it is the largest
        while(total_nodes < current_nodes){
            complete_nodes = total_nodes;
            total_nodes += (1 << level);
            level++;    
        }
        ll left_nodes = 0, right_nodes = 0;
        ll last_nodes = current_nodes - complete_nodes;
        ll last_full_nodes = (total_nodes - complete_nodes);
        if(last_nodes >= last_full_nodes/2){
            left_nodes = last_full_nodes/2;
            right_nodes = (current_nodes - complete_nodes - last_full_nodes/2);
        }
        else{
            left_nodes = current_nodes - complete_nodes;
            right_nodes = 0;
        }
        left_nodes += complete_nodes / 2;
        right_nodes += complete_nodes / 2;
        ans[i] = c[current_nodes][left_nodes];
        ans[i] = (ans[i] * ans[left_nodes])%MOD;
        ans[i] = (ans[i] * ans[right_nodes])%MOD;
    }
    return ans[n];
}
