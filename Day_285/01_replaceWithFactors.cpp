// Question Link: https://www.interviewbit.com/problems/replace-with-factors/

/*
Replace With Factors!

Problem Description:
Rishabh has given you a linked list in the form of its head node A. He has also given you an integer B.
You need to change the value of each node to its nearest multiple of B that is <= current value.

Problem Constraints:
1 <= size of list <= 10^5
1 <= value of each node <= 10^5
1 <= B <= 10^5

Input Format:
First argument is the head pointer of linked list A.
Second argument is the integer B.

Output Format:
Return the head of the changed linked list.

Example Input:
Input 1:
A = 1 -> 2 -> 3
B = 2
Input 2:
A = 3 -> 4 -> 5
B = 3

Example Output:
Output 1:
0 -> 2 -> 2
Output 2:
3 -> 3 -> 3

Example Explanation:
Explanation 1:
All numbers have been replaced by nearest multiples of 2.
Explanation 2:
All numbers have been replaced by nearest multiples of 3.
*/



/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::solve(ListNode* A, int B) {
    ListNode* head = A;
        
    while(head != NULL)  {
            head->val -= ((head->val)%B);
            head = head->next;
    }
    
    return A;
}
