// Question Link: https://www.interviewbit.com/problems/merge-two-sorted-lists/

/*
Merge Two Sorted Lists:

Merge two sorted linked lists and return it as a new list. 

The new list should be made by splicing together the nodes of the first two lists, and should also be sorted.

For example, given following linked lists :
  5 -> 8 -> 20 
  4 -> 11 -> 15
  
The merged list should be :
4 -> 5 -> 8 -> 11 -> 15 -> 20
*/



/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::mergeTwoLists(ListNode* A, ListNode* B) {
    priority_queue<int,vector<int>,greater<int>> pq;
   
    while(A! = NULL) {
        pq.push(A->val);
        A=A->next;
    }
   
    while(B! = NULL) {
        pq.push(B->val);
        B=B->next;
    }
   
    ListNode* start = new ListNode(-1);
    ListNode* prev = start;
    
    while(!pq.empty()) {
        int a = pq.top();
        pq.pop();
       
        ListNode* node = new ListNode(a);
        prev->next = node;
        prev = node;
    }
   
    return start->next;
}

