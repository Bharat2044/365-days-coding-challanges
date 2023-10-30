// Question Link: https://leetcode.com/problems/sort-list/

/*
148. Sort List

Given the head of a linked list, return the list after sorting it in ascending order.

Example 1:
Input: head = [4,2,1,3]
Output: [1,2,3,4]
Example 2:
Input: head = [-1,5,3,4,0]
Output: [-1,0,3,4,5]
Example 3:
Input: head = []
Output: []
 
Constraints:
The number of nodes in the list is in the range [0, 5 * 104].
-105 <= Node.val <= 105
 
Follow up: Can you sort the linked list in O(n logn) time and O(1) memory (i.e. constant space)?
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
    void mergesorting(ListNode** head){
        ListNode*first;
        ListNode*second;
        ListNode*current=*head;
        if(!current || !current->next)return;

        middle(current,&first,&second);

        mergesorting(&first);
        mergesorting(&second);

        *head=merge(first,second);
    }

    void middle(ListNode* current,ListNode** first,ListNode** second){
        ListNode* fast=current->next;
        ListNode* slow=current;

        while(fast!=NULL){
            fast=fast->next;
            if(fast!=NULL){
                fast=fast->next;
                slow=slow->next;
            }
        }
        *first=current;
        *second=slow->next;
        slow->next=NULL;
    }

    ListNode* merge(ListNode* first,ListNode* second){
        ListNode* final=NULL;

        if(!first)return second;
        if(!second)return first;

        if(first->val <= second->val){
            final=first;
            final->next=merge(first->next,second);
        }

        else{
            final=second;
            final->next=merge(first,second->next);
        }
        return final;
    }

    ListNode* sortList(ListNode* head) {
        mergesorting(&head);
        return head;
    }
};
