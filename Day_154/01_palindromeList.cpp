// Question Link: https://www.interviewbit.com/problems/palindrome-list/

/*
Palindrome List

Problem Description:
Given a singly linked list A, determine if it's a palindrome. Return 1 or 0, denoting if it's a palindrome or not, respectively.

Problem Constraints:
 1 <= |A| <= 105 

Input Format:
The first and the only argument of input contains a pointer to the head of the given linked list. 

Output Format:
 Return 0, if the linked list is not a palindrome. 
 Return 1, if the linked list is a palindrome. 

Example Input:
 Input 1: 
A = [1, 2, 2, 1]
Input 2:
A = [1, 3, 2]

Example Output:
 Output 1: 
 1 
 Output 2: 
 0 

Example Explanation:
Explanation 1:
 The first linked list is a palindrome as [1, 2, 2, 1] is equal to its reversed form.
Explanation 2:
 The second linked list is not a palindrom as [1, 3, 2] is not equal to [2, 3, 1].
*/




/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* reverse(ListNode* head){
    ListNode* dummy=NULL;
    ListNode* prev=head;

    while(prev){
        ListNode* nex=prev->next;
        prev->next=dummy;
        dummy=prev;
        prev=nex;
    }

    return dummy;
}

int Solution::lPalin(ListNode* A) {
    ListNode* slow=A;
    ListNode* fast=A;

    while(fast->next&&fast->next->next){
        fast=fast->next->next;
        slow=slow->next;
    }

    slow->next=reverse(slow->next);
    slow=slow->next;
    fast=A;

    while(slow){
        if(slow->val!=fast->val) 
            return 0;
        
        slow=slow->next;
        fast=fast->next;
    }

    return 1;
}

