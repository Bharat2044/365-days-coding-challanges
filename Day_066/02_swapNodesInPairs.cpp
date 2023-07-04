// Question Link: https://leetcode.com/problems/swap-nodes-in-pairs/

/*
24. Swap Nodes in Pairs

Given a linked list, swap every two adjacent nodes and return its head. You must solve the problem without modifying the values in the list's nodes (i.e., only nodes themselves may be changed.)

Example 1:
Input: head = [1,2,3,4]
Output: [2,1,4,3]
Example 2:
Input: head = []
Output: []
Example 3:
Input: head = [1]
Output: [1] 

Constraints:
The number of nodes in the list is in the range [0, 100].
0 <= Node.val <= 100
  */




class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        // if head is NULL OR just having a single node, then no need to change anything 
        if(head == NULL || head -> next == NULL) 
        {
            return head;
        }
            
        ListNode* temp; // temporary pointer to store head -> next
        temp = head->next; // give temp what he want
        
        head->next = swapPairs(head->next->next); // changing links
        temp->next = head; // put temp -> next to head
        
        return temp; // now after changing links, temp act as our head
    }
};
