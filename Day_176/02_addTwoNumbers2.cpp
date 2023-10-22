// Question Link: https://leetcode.com/problems/add-two-numbers-ii/

/*
445. Add Two Numbers II

You are given two non-empty linked lists representing two non-negative integers. The most significant digit comes first and each of their nodes contains a single digit. Add the two numbers and return the sum as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.

Example 1:
Input: l1 = [7,2,4,3], l2 = [5,6,4]
Output: [7,8,0,7]
Example 2:
Input: l1 = [2,4,3], l2 = [5,6,4]
Output: [8,0,7]
Example 3:
Input: l1 = [0], l2 = [0]
Output: [0]
 
Constraints:
The number of nodes in each linked list is in the range [1, 100].
0 <= Node.val <= 9
It is guaranteed that the list represents a number that does not have leading zeros.
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
    
    ListNode* reverse(ListNode* head){
        ListNode *p, *q;
        p=head, q=NULL;
        
        while(p!=NULL){
            ListNode* on=p->next; // keep track of original next node
            p->next=q; // reversing links
            q=p;
            p=on;
        }
        return q;
    }
    
    ListNode* addTwoNumbers(ListNode* head1, ListNode* head2) {
        ListNode* p=reverse(head1);
        ListNode* q=reverse(head2);
        
        ListNode *head, *last;
        head=last=new ListNode(-1); // pointers to new list
        
        int carry=0;
        while(p!=NULL || q!=NULL){
            int d=(p!=NULL ? p->val:0) + (q!=NULL ? q->val:0) + carry;
            
            ListNode *temp=new ListNode(d%10);
            last->next=temp;
            last=temp;
            
            carry=d/10;
            
            if(p) p=p->next;
            if(q) q=q->next;
        }
        
        if(carry!=0){
            ListNode *temp=new ListNode(carry);
            last->next=temp;
            last=temp;
        }
        
        head=head->next; // since head was pointing to dummy node
        head=reverse(head);
        
        return head;
    }
};
