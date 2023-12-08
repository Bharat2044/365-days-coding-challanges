// Question Link: https://www.interviewbit.com/problems/reverse-linked-list/

/*
Reverse Linked List

Reverse a linked list. Do it in-place and in one-pass.

For example:
Given 1->2->3->4->5->NULL,
return 5->4->3->2->1->NULL.

PROBLEM APPROACH :
Complete solution code in the hints
*/



/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::reverseList(ListNode* A) {
     ListNode *curr=A;

    ListNode *prev=NULL;

    while(curr!=NULL){

        ListNode *temp= curr->next;

        curr->next=prev;

        prev=curr;

        curr=temp;

    }

    return prev;
}
