// Question Link: https://www.interviewbit.com/problems/reverse-link-list-recursion/

/*
Reverse Link List Recursion

Reverse a linked list using recursion.

Example :
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
ListNode* rec(ListNode* A)
{
    if(A==NULL || A->next == NULL) 
        return A;
   
    ListNode* newhead = rec(A->next);
    A->next->next = A;
    A->next = NULL;
    
    return newhead;
}

ListNode* Solution::reverseList(ListNode* A) {
    return rec(A);
}
