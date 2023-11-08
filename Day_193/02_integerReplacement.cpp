// Question Link: https://leetcode.com/problems/integer-replacement/

/*
397. Integer Replacement

Given a positive integer n, you can apply one of the following operations:

If n is even, replace n with n / 2.
If n is odd, replace n with either n + 1 or n - 1.
Return the minimum number of operations needed for n to become 1.

Example 1:
Input: n = 8
Output: 3
Explanation: 8 -> 4 -> 2 -> 1
Example 2:
Input: n = 7
Output: 4
Explanation: 7 -> 8 -> 4 -> 2 -> 1
or 7 -> 6 -> 3 -> 2 -> 1
Example 3:
Input: n = 4
Output: 2

Constraints:
1 <= n <= 231 - 1
*/



class Solution {
public:
    int integerReplacement(int n) {

        queue<long long int>q;
        q.push(n);

        // to avoid revisiting elements 
        // because throught bfs we are going to reach any element in min. operations
        unordered_set<int>s;

        int steps = 0;
        while(!q.empty()){
            int size = q.size();
            
            while(size--){
                long long int curr = q.front(); q.pop();
                // current element is the target
                if(curr == 1) return steps;
                
                if(curr%2 == 0){
                    //if the element we are going to insert is 1
                    if(curr/2 == 1) return steps+1;
                    if(!s.count(curr/2)){
                        q.push(curr/2);
                        s.insert(curr/2);
                    }
                }
                else{
                    //if the element we are going to insert is 1
                    if(curr+1==1 || curr-1==1) return steps+1;
                    if(!s.count(curr+1)) q.push(curr+1);
                    if(!s.count(curr-1)) q.push(curr-1);
                    
                    s.insert(curr+1); s.insert(curr-1);
                }
            }
            steps++;
        }
        
        return -1;
    }
};
