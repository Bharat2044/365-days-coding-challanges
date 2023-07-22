// Question Link: https://www.interviewbit.com/problems/reverse-link-list-ii/

/*
Reverse Link List II

Reverse a linked list from position m to n. Do it in-place and in one-pass.

For example:
Given 1->2->3->4->5->NULL, m = 2 and n = 4,

return 1->4->3->2->5->NULL.

Note:
Given m, n satisfy the following condition:

1 ≤ m ≤ n ≤ length of list.

Note 2:
Usually the version often seen in the interviews is reversing the whole linked list which is obviously an easier version of this question.
*/




/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::reverseBetween(ListNode* A, int B, int C) {
    if(A==NULL || A->next==NULL) 
        return A;
   
    ListNode * m=A;
    ListNode * n=A;
    ListNode * x = A;
    int b=1;
    
    while(b<B)
    {   x=m;
        m=m->next;
        b+=1;
    }
   
    int c=1;
   
    while(c<=C)
    {
        n=n->next;
        c+=1;
    }
   
    ListNode * p =NULL;
    ListNode * q=m;
    ListNode*r;
   
    int count=1;
   
    while(count<=C-B+1)
    {  
        r=q->next;
        q->next=p;
        p=q;
        q=r;  
        count+=1;    
    }
   
    if (x == m) 
        A = p;
    else 
        x->next = p;
    
    m->next = q;
    return A;
}



