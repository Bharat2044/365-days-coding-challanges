// Question Link: https://www.interviewbit.com/problems/remove-duplicates-from-sorted-list/

/*
Remove Duplicates from Sorted List

Given a sorted linked list, delete all duplicates such that each element appear only once.

For example,
Given 1->1->2, return 1->2.
Given 1->1->2->3->3, return 1->2->3.
*/



/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::deleteDuplicates(ListNode* A) {
    ListNode*curr=A;
    
    while(curr!=NULL && curr->next!=NULL){
        if(curr->val==curr->next->val){
            ListNode*todelete=curr->next;
            ListNode*next_next=curr->next->next;
            delete(todelete);
            curr->next=next_next;
        }
        else{
            curr=curr->next;
        }
    }
    
    return A;
}
