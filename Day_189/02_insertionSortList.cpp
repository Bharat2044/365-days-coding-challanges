// Question Link: https://leetcode.com/problems/insertion-sort-list/

/*
147. Insertion Sort List

Given the head of a singly linked list, sort the list using insertion sort, and return the sorted list's head.

The steps of the insertion sort algorithm:

Insertion sort iterates, consuming one input element each repetition and growing a sorted output list.
At each iteration, insertion sort removes one element from the input data, finds the location it belongs within the sorted list and inserts it there.
It repeats until no input elements remain.
The following is a graphical example of the insertion sort algorithm. The partially sorted list (black) initially contains only the first element in the list. One element (red) is removed from the input data and inserted in-place into the sorted list with each iteration.

Example 1:
Input: head = [4,2,1,3]
Output: [1,2,3,4]
Example 2:
Input: head = [-1,5,3,4,0]
Output: [-1,0,3,4,5]
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
    ListNode* insertionSortList(ListNode* head) {
        ListNode* newHead = NULL;//initializing the newHead for our sorted linkedlist
        while(head){
            // Exluding node from the original linked list we will do this one at a time
            ListNode* temp = head;
            head = head->next;
            temp->next=NULL;
            
            //setting the first node of our final linked list 
            if(newHead == NULL) newHead = temp;
             // if the position of element is at index 0 i.e. at the start (the temp node is the smallest of all the nodes that are currently present in the sorted linked list)
            else if(newHead->val >= temp->val){
                temp->next = newHead;
                newHead = temp;
            }
            // inserting the node anywhere in the middle or in the end depending upon the value of the temp node;
            else{
                ListNode* root = newHead;
                {
                while(root->next){
                    if(temp->val > root->val and temp->val <= root->next->val){
                        temp->next = root->next;
                        root->next = temp;
                        break;
                    }
                    root = root->next;
                }  
                    //inserting the temp node at the end
                    if(root->next==NULL) root->next = temp;
                    
                }
            }
        }
        //Our sorted linkedlist
        return newHead;
    }
};
