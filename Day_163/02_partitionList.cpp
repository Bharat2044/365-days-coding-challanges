// Question Link: https://leetcode.com/problems/partition-list/

/*
86. Partition List

Given the head of a linked list and a value x, partition it such that all nodes less than x come before nodes greater than or equal to x.

You should preserve the original relative order of the nodes in each of the two partitions.

Example 1:
Input: head = [1,4,3,2,5,2], x = 3
Output: [1,2,2,4,3,5]
Example 2:
Input: head = [2,1], x = 2
Output: [1,2]
 
Constraints:
The number of nodes in the list is in the range [0, 200].
-100 <= Node.val <= 100
-200 <= x <= 200
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
    ListNode* partition(ListNode* head, int x) {
        if(head==NULL) return head;
        if(head->next == NULL) return head;

        if(head->val >= x){
            ListNode* k1,*k2;
            k2 = head->next;
            k1 = head;

            while(k2 && k2->val>=x){                            
                k1 = k1->next;
                k2 = k2->next;
            }
            
            if(k2!=NULL){
                k1->next = k2->next;
                k2->next = head;
                head = k2;
            }
        }

        ListNode* l1,*l2,*l3;
        l1 = head;

        while(l1 && l1->next && l1->next->val < x && l1->val < x){
            l1 = l1->next;
        }    
        if(l1==NULL){
            return head;
        }      

        l2 = l1;
        l3 = l1->next;

        while(l3&&l2){
            if(l3->val >= x){
                l3 = l3->next;
                l2 = l2->next;
                continue;
            }
            l2->next = l3->next;
            l3->next = l1->next;
            l1->next = l3;
            l1 = l1->next;
            l3 = l2->next;
        }

        return head;
    }
};
