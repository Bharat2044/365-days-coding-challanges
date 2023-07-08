// Question Link: https://leetcode.com/problems/rotate-list/

/*
61. Rotate List

Given the head of a linked list, rotate the list to the right by k places.

Example 1:
Input: head = [1,2,3,4,5], k = 2
Output: [4,5,1,2,3]
Example 2:
Input: head = [0,1,2], k = 4
Output: [2,0,1]

Constraints:
The number of nodes in the list is in the range [0, 500].
-100 <= Node.val <= 100
0 <= k <= 2 * 109
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
    int getlength(ListNode* head1)
    {
        int count=1;
        while(head1->next!=NULL)
        {
            count++;
            head1=head1->next;
        }
        return count;
    }
    
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==NULL || head->next==NULL)return head;
        int l=getlength(head);
        k=k%l;

        for(int i=1;i<=k;i++)
        { 
            ListNode* tail=head;
            ListNode* tailprev=NULL;
            while(tail->next!=NULL)
            {
                tailprev=tail;
                tail=tail->next;

            }

            tail->next=head;
            tailprev->next=NULL;
            head=tail;
        }

        return head;
    }
};
