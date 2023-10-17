// Question Link: https://www.interviewbit.com/problems/copy-list/

/*
Copy List

A linked list is given such that each node contains an additional random pointer which could point to any node in the list or NULL.

Return a deep copy of the list.

Example:
Given list
   1 -> 2 -> 3
with random pointers going from
  1 -> 3
  2 -> 1
  3 -> 1
You should return a deep copy of the list. The returned answer should not contain the same node as the original list, but a copy of them. The pointers in the returned list should not link to any node in the original input list.
  */



/**
 * Definition for singly-linked list.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
RandomListNode* Solution::copyRandomList(RandomListNode* head) {
    RandomListNode* A = head;
    if(A == NULL)
        return A;
   
    unordered_map<RandomListNode*, RandomListNode*> mp; // {original, copy}
   
    // store all original LL nodes corresponding newly created copy nodes, just create with same label
    // do not worry about random pointer
    RandomListNode* copyHead = new RandomListNode(A->label);
    mp[A] = copyHead;
    RandomListNode* copy = copyHead;
    A = A->next;
   
    while(A){
        copy->next = new RandomListNode(A->label);
        copy = copy->next;
        mp[A] = copy;
        A = A->next;
    }
   
    //now modify the random
    // check for original LL node and modify corresponding copy LL node->random
    A = head;
    copy = copyHead;
    while(A){
        if(A->random && mp.find(A->random) != mp.end())
            copy->random = mp[A->random];
        copy = copy->next;
        A = A->next;
    }
   
    return copyHead;
}
