// Question Link: https://leetcode.com/problems/reverse-nodes-in-k-group/

/*
25. Reverse Nodes in k-Group

Given the head of a linked list, reverse the nodes of the list k at a time, and return the modified list.

k is a positive integer and is less than or equal to the length of the linked list. If the number of nodes is not a multiple of k then left-out nodes, in the end, should remain as it is.

You may not alter the values in the list's nodes, only nodes themselves may be changed.

Example 1:
Input: head = [1,2,3,4,5], k = 2
Output: [2,1,4,3,5]
Example 2:
Input: head = [1,2,3,4,5], k = 3
Output: [3,2,1,4,5]
 
Constraints:
The number of nodes in the list is n.
1 <= k <= n <= 5000
0 <= Node.val <= 1000
*/



/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    int length(ListNode* head){
        int count=0;
        while(head){
            count++;
            head= head->next;
        }
        return count;
    }

    ListNode*solve(ListNode*head, int k, int size){
        int count = 0;
        ListNode* curr = head, * prev = NULL,* nxt = NULL;
        while(count < k && curr){
            nxt = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nxt;
            count++;
        }
        size -= k;

        if(nxt && size >= k){
            head->next = solve(nxt , k, size);
        }
        else head->next = nxt;
        return prev;
    }
    
    ListNode* reverseKGroup(ListNode* head, int k) {
        return solve(head, k, length(head));
    }
};
