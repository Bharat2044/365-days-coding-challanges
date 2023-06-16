// Question Link: https://www.interviewbit.com/problems/reorder-list/

/*
Reorder List

Given a singly linked list
    L: L0 → L1 → … → Ln-1 → Ln,
reorder it to:
    L0 → Ln → L1 → Ln-1 → L2 → Ln-2 → …
You must do this in-place without altering the nodes’ values.

For example,
Given {1,2,3,4}, reorder it to {1,4,2,3}.
*/




void reverseList(ListNode* &head) {
        ListNode* prev=NULL;
        ListNode* curr=head;
        ListNode* next=head;
        
        while(next != NULL){
            next =curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
        }
        
        head=prev;
        return;
 }
    
ListNode* Solution::reorderList(ListNode* A) {
    int count = 0;
    ListNode* temp = A;
    
    if(A==NULL || A->next==NULL || A->next->next==NULL) 
        return A;
    
    while(temp != NULL){
        temp = temp->next;
        count++;
    }
    
    int n;
    if(count%2 == 0) 
        n = count/2 -1;
    else 
        n = count/2;
   
   ListNode* temp1 = A;
   while(n>0 && temp1!=NULL){
        temp1= temp1->next;
        n--;
   }
   
    ListNode* head = temp1->next;
    temp1->next = NULL;

    reverseList(head);    
    ListNode* res = A;
   
    ListNode* curr1 = A;
    ListNode* curr2 = head;
    ListNode* temp2 = A->next;
    ListNode* temp3 = head->next;

    while(curr1 != NULL && curr2 != NULL){
        curr1 = A->next;
        A->next = curr2;
        temp2 = curr1;
        A = temp2;
        curr2 = head->next;
        head->next = curr1;
        temp3 = curr2;
        head = temp3;  
    }
   
    return res;
}
