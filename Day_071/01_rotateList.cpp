// Question Link: https://www.interviewbit.com/problems/rotate-list/

/*
Rotate List

Problem Description:
Given a list, rotate the list to the right by k places, where k is non-negative.

Problem Constraints:
1 <= B <= 109

Input Format:
The first argument is ListNode A, pointing to the head of the list.
The second argument is an integer B, representing the value of k.

Output Format:
Return the rotated list.

Example Input:
A = 1->2->3->4->5->NULL
B = 2

Example Output:
4->5->1->2->3->NULL

Example Explanation:
Given list: A = 1->2->3->4->5->NULL
Given B = 2;
After rotating A once, A = 5->1->2->3->4->NULL
After rotating A again, A = 4->5->1->2->3->NULL
Hence after rotating the given list A, for B = 2, return 4->5->1->2->3->NULL
*/




/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::rotateRight(ListNode* A, int B) {

    ListNode* st=A,*end,*c;

    int size=0;

    while(st){

        size++;

        if(!st->next)end=st;

        st=st->next;

    }

    B=B%size;

    B=(size-B)%size;

    if(size==0||size==1||B==0)return A;

    B--;

    st=A;

    while(B--){

        st=st->next;

    }

    c=st->next;

    st->next=NULL;

    end->next=A;

    return c;

}
