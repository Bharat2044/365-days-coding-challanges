// Question Link: https://www.interviewbit.com/problems/sort-list/

/*
Sort List

Sort a linked list in O(n log n) time using constant space complexity.

Example :
Input : 1 -> 5 -> 4 -> 3

Returned list : 1 -> 3 -> 4 -> 5
*/


ListNode* Solution::sortList(ListNode* A) {
    if (A == NULL || A->next == NULL) {
        return A;
    }

    // Counting the number of nodes in the list
    int count = 0;
    ListNode* curr = A;
    while (curr != NULL) {
        count++;
        curr = curr->next;
    }

    // Convert the linked list to an array
    vector<int> arr(count);
    curr = A;
    for (int i = 0; i < count; i++) {
        arr[i] = curr->val;
        curr = curr->next;
    }

    // Sort the array
    sort(arr.begin(), arr.end());

    // Update the linked list with the sorted values
    curr = A;
    for (int i = 0; i < count; i++) {
        curr->val = arr[i];
        curr = curr->next;
    }

    return A;
}
