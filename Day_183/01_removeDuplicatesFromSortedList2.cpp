// Question Link: https://www.interviewbit.com/problems/remove-duplicates-from-sorted-list-ii/

/*
Remove Duplicates from Sorted List II

Given a sorted linked list, delete all nodes that have duplicate numbers, leaving only distinct numbers from the original list.

For example,
Given 1->2->3->3->4->4->5, return 1->2->5.
Given 1->1->1->2->3, return 2->3.
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
    ListNode *head = new ListNode(0);
    head->next = A;
    ListNode *prev = head;
    ListNode *p = A;
    
    while(p && p->next){
        ListNode *q = p->next;
        while(q && p->val == q->val){
            ListNode* r = p->next;
            
            while(r && p->val == r->val){
                r = r->next;
            }
            
            p = r;
            if (p) {
                q = p->next;
            } else {
                q = nullptr;
            }
        }
        
        prev->next = p;
        prev = prev->next;
        
        if (q) {
            p = q;
        }
    }
    
    return head->next;
}

