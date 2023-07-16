// Question Link: https://www.interviewbit.com/problems/insertion-sort-list/

/*
Insertion Sort List

Sort a linked list using insertion sort.

We have explained Insertion Sort at Slide 7 of Arrays

Insertion Sort Wiki has some details on Insertion Sort as well.

Example :
Input : 1 -> 3 -> 2
Return 1 -> 2 -> 3
*/





/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::insertionSortList(ListNode* A) {
    if(A->next==NULL) 
        return A;
        
    ListNode* head = new ListNode(0);
    ListNode* cur = head;
    cur -> next = A;
    
    while(cur->next != NULL) {
        ListNode* i = head;
        while((i!=cur) && (cur->next->val > i->next->val))
        i = i->next ;
        
        if (i==cur) 
            cur = cur->next;
        else {
            ListNode* t1 = cur->next;
            ListNode* t2 = i->next;
            i->next = cur->next;
            cur->next = t1->next;
            t1->next = t2;
        }
    }
    
    return head->next;
}

