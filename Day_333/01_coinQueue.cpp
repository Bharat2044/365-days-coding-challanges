// Question Link: https://www.interviewbit.com/problems/coin-queue/

/*
Coin Queue

Problem Description:
You need to maintain a queue that is initially empty. You will perform three types of operations on the queue -
1 X - Add the number x to the queue.
2 0 - Remove the least recently added number from the queue.
3 X - Consider the current numbers in the queue. Find the maximum size of a subset of numbers in the queue whose sum is X. If there is no such subset, return -1.
A subset is defined as a sequence that can be obtained by removing some (possibly all) elements present in the queue.

Problem Constraints:
1 <= X <= 350
|A| <= 10^5

Input Format:
The only argument contains a 2D array A, denoting the operations on the queue.

Output Format:
Return an array containing the answers to each query of type 3.

Example Input:
Input 1:
  A : 
  [
    [1, 3]
    [1, 1]
    [1, 1]
    [2, 0]
    [3, 2]
  ]
Input 2:
  A : 
  [
    [1, 1]
    [1, 2]
    [1, 2]
    [1, 3]
    [3, 4]
    [3, 5]
  ]

Example Output:
Output 1:
  [2]
Output 2:
  [2, 3]

Example Explanation:
Explanation 1:
  After first 3 operations, queue becomes {3, 1, 1}.
  Then we pop the number 3. The queue is {1, 1}.
  Then we can form 2 by taking both the ones. So, we have a subset of 2 numbers.
Explanation 2:
  After first 3 operations, queue becomes {1, 2, 2, 3}.
  Then 4 can be formed by 2 + 2 and 1 + 3. Max 2 numbers are in a subset.
  5 can be formed by 1 + 2 + 2, 2 + 3 and 2 + 3. Max 3 numbers are in a subset.
*/



stack< pair< int, vector<int> > > s[2];
void clear(int idx){
    while(s[idx].size())
        s[idx].pop();
}
void push(int idx, int x){
    if(s[idx].size() == 0){
        vector<int> v(351, -1);
        v[0] = 0;
        v[x] = 1;
        s[idx].push({x, v});
        return;
    }
    vector<int> v = s[idx].top().second;
    for(int i = 350; i >= x; i--){
        if(v[i-x] != -1)
            v[i] = max(v[i], 1 + v[i-x]); 
    }
    s[idx].push({x, v});
}
vector<int> Solution::solve(vector<vector<int> > &A) {
    clear(0);
    clear(1);
    int q, type, x;
    q = A.size();
    vector<int> res;
    for(int i = 0; i < q; i++){
        type = A[i][0], x =A[i][1];
        if(type == 1)
            push(0, x);
        else if(type == 2){
            if(s[1].size())
                s[1].pop();
            else{
                while(s[0].size() > 1){
                    push(1, s[0].top().first);
                    s[0].pop();
                }
                s[0].pop();
            }
        }
        else{
            if(s[0].size() == 0 and s[1].size() == 0)
                res.push_back(-1);
            else if(s[0].size() == 0)
                res.push_back(s[1].top().second[x]);
            else if(s[1].size() == 0)
                res.push_back(s[0].top().second[x]);
            else{
                int ans = -1;
                for(int i = 0; i <= x; i++){
                    if(s[0].top().second[i] != -1 and s[1].top().second[x - i] != -1)
                        ans = max(ans, s[0].top().second[i] + s[1].top().second[x - i]);
                }
                res.push_back(ans);
            }
        }
    }
    return res;
}
