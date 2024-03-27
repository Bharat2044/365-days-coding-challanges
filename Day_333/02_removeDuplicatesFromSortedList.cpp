// Question Link: https://leetcode.com/problems/remove-duplicates-from-sorted-list-ii/

/*
82. Remove Duplicates from Sorted List II

Given the head of a sorted linked list, delete all nodes that have duplicate numbers, leaving only distinct numbers from the original list. Return the linked list sorted as well.

Example 1:
Input: head = [1,2,3,3,4,4,5]
Output: [1,2,5]
Example 2:
Input: head = [1,1,1,2,3]
Output: [2,3]
 
Constraints:
The number of nodes in the list is in the range [0, 300].
-100 <= Node.val <= 100
The list is guaranteed to be sorted in ascending order.
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
    ListNode* deleteDuplicates(ListNode* head) {
    //    myset.erase(valueOfElementToBeDeleted);
    if(head == NULL){
        return head;
    }
        set<int> st;
        bool flag = false;
        vector<int> v;
    ListNode *temp = head;
    while(temp != NULL){
        if(st.find(temp ->val) != st.end()){
            v.push_back(temp->val);

        }
        else{
            st.insert(temp->val);
        }
            temp = temp->next;
       
    }
      for(int i = 0; i<v.size();i++){
          if(st.find(v[i]) != st.end()){
              st.erase(v[i]);
          }
      }
      v.clear();
     for(auto i : st){
         v.push_back(i);
     }
     if(v.size() == 0){
         head = NULL;
         return head;
     }
      temp = head;
      ListNode * prev;
      for(int i = 0; i<v.size();i++){
          temp->val = v[i];
          prev = temp;
          temp = temp->next; 
      }
     prev ->next = NULL;
        return head;
    }
};
