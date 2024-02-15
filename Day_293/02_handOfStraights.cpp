// Question Link: https://leetcode.com/problems/hand-of-straights/

/*
846. Hand of Straights

Alice has some number of cards and she wants to rearrange the cards into groups so that each group is of size groupSize, and consists of groupSize consecutive cards.
Given an integer array hand where hand[i] is the value written on the ith card and an integer groupSize, return true if she can rearrange the cards, or false otherwise.

Example 1:
Input: hand = [1,2,3,6,2,3,4,7,8], groupSize = 3
Output: true
Explanation: Alice's hand can be rearranged as [1,2,3],[2,3,4],[6,7,8]
Example 2:
Input: hand = [1,2,3,4,5], groupSize = 4
Output: false
Explanation: Alice's hand can not be rearranged into groups of 4.

Constraints:
1 <= hand.length <= 104
0 <= hand[i] <= 109
1 <= groupSize <= hand.length
*/


class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        priority_queue<int ,vector<int>,greater<int>> pq;
        vector<int>a;
        for(auto it:hand)
        pq.push(it);
        int temp=1;
        int i=0;
        while(i<hand.size()){
        int prev=pq.top();
        pq.pop();
        while(temp<groupSize && !pq.empty()){
            if(pq.top()-1==prev){
            prev= pq.top();
            pq.pop();
            temp++;
            }
            else if(pq.top()==prev){
                a.push_back(pq.top());
                pq.pop();
            }
            else{
                return false;
            }
        }
        if(temp!=groupSize){
            return false;
        }
        for(int i=0;i<a.size();i++){
            pq.push(a[i]);
        }
        a.resize(0);
        i=i+temp;
        temp=1;
    }
        return true;
    }
};
