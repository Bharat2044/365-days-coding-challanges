// Question Link: https://www.interviewbit.com/problems/merge-k-sorted-lists/

/*
Merge K Sorted Lists

Merge k sorted linked lists and return it as one sorted list.

Example :
1 -> 10 -> 20
4 -> 11 -> 13
3 -> 8 -> 9
will result in
1 -> 3 -> 4 -> 8 -> 9 -> 10 -> 11 -> 13 -> 20
*/


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::mergeKLists(vector<ListNode*> &A) {
    // Min heap
    priority_queue<pair<int,ListNode*>,vector<pair<int,ListNode*>>,greater<pair<int,ListNode*>>>pq;
    int k=A.size();
    
    for(int i=0;i<k;i++)
        pq.push({A[i]->val,A[i]});
    
    ListNode* head = new ListNode(pq.top().first);
    ListNode* temp=head;
    
    ListNode* del = pq.top().second;
    del=del->next;
    pq.pop();
    
    if(del!=NULL)
        pq.push({del->val,del});
    
    while(!pq.empty()) {
        auto ele=pq.top();
        pq.pop();
        
        ListNode* curr = ele.second;
        temp->next=curr;
        temp=temp->next;
        curr=curr->next;
        
        if(curr!=NULL)
            pq.push({curr->val,curr});
    }
    
    temp->next=NULL;
    return head;
}
