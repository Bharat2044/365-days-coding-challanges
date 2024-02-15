// Question Link: https://www.interviewbit.com/problems/k-reverse-linked-list/

/*
K reverse linked list

Given a singly linked list and an integer K, reverses the nodes of the
list K at a time and returns modified linked list.

NOTE : The length of the list is divisible by K

Example :
Given linked list 1 -> 2 -> 3 -> 4 -> 5 -> 6 and K=2,
You should return 2 -> 1 -> 4 -> 3 -> 6 -> 5
Try to solve the problem using constant extra space.
*/



/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::reverseList(ListNode* A, int B) {
    if(A==NULL||B==1) 
        return A;

    ListNode* dummy=new ListNode(0);
    dummy->next=A;
    
    ListNode* prev=dummy;
    ListNode* curr=dummy;
    ListNode* nex=dummy;
    int count=0;

    while(curr){
        curr=curr->next;
        count++;
    }
    
    while(count>=B){
        curr=prev->next;
        nex=curr->next;

        for(int i=1;i<B;i++){
            curr->next=nex->next;
            nex->next=prev->next;
            prev->next=nex;
            nex=curr->next;
        }

        prev=curr;
        count-=B;
    }

    return dummy->next;    
}
