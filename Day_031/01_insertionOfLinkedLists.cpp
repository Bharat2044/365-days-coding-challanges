// Question Link: https://www.interviewbit.com/problems/intersection-of-linked-lists/

/*
Intersection of Linked Lists:

Write a program to find the node at which the intersection of two singly linked lists begins.

For example, the following two linked lists:

A:          a1 → a2
                   ↘
                     c1 → c2 → c3
                   ↗
B:     b1 → b2 → b3

begin to intersect at node c1.

Notes:
If the two linked lists have no intersection at all, return null.
The linked lists must retain their original structure after the function returns.
You may assume there are no cycles anywhere in the entire linked structure.
Your code should preferably run in O(n) time and use only O(1) memory.
Problem approach completely explained :

Complete code in the hints section.
*/


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::getIntersectionNode(ListNode* A, ListNode* B) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    int c1 = 0, c2 = 0;
       
    ListNode* temp_A = A;
    ListNode* temp_B = B;
    
    while(temp_A){
        c1++;
        temp_A = temp_A->next;
    }
    
    while(temp_B){
        c2++;
        temp_B = temp_B->next;
    }
    int diff = abs(c2  -c1);
    
    ListNode* temp  = (c2 > c1) ? B : A ;
    ListNode* oth_temp  = (c2 <= c1) ? B : A ;
    
    while(diff){
        temp = temp->next;
        diff--;
    }
    
    while(temp){
       
        if(temp == oth_temp)
            return temp;
       
        temp = temp->next;
        oth_temp = oth_temp->next;
    }
    
    return NULL;

}
