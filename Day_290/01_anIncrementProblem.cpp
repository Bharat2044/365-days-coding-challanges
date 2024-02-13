// Question Link: https://www.interviewbit.com/problems/an-increment-problem/

/*
An Increment Problem

Problem Description:
Given a stream of numbers A. On arrival of each number, you need to increase its first occurrence by 1 and include this in the stream.
Return the final stream of numbers.

Note: You will traverse the stream from left to right and update the first occurrence of the number by 1, if found.

Problem Constraints:
1 <= |A| <= 100000
1 <= A[i] <= 10000

Input Format:
First and only argument is the array A.

Output Format:
Return an array, the final stream of numbers.

Example Input:
Input 1: 
A = [1, 1]
Input 2:
A = [1, 2]
Input 3:
A = [1, 1, 2, 2]

Example Output:
Output 1:
[2, 1]
Output 2:
[1, 2]
Output 3:
[3, 1, 3, 2]

Example Explanation:
Explanation 1:
On arrival of the second element, the other element is increased by 1.
Explanation 2:
No increases are to be done.
Explanation 3:
Stream after arrival of numbers (1-based indexing):
  First number  (1): [1]          , Simply push 1 to the stream
  Second number (1): [2, 1]       , Increment first occurence of 1, present at 1st Index and push 1 to the stream
  Third number  (2): [3, 1, 2]    , Increment first occurence of 2, present at 1st Index and push 2 to the stream
  Fourth number (2): [3, 1, 3, 2] , Increment first occurence of 2, present at 3rd Index and push 2 to the stream
*/



vector<int> Solution::solve(vector<int> &A) {
    unordered_map<int, set<int>> mp;
    int n = A.size();
    
    for (int i = 0; i < n; i++) {
        if (mp.find(A[i]) == mp.end())
            mp[A[i]].insert(i);
        else {
            int pos = *mp[A[i]].begin();
            A[pos]++;               // increase in vector
            mp[A[i]].erase(pos);    // erase cuz this pos no longer belongs to A[i]
            mp[A[pos]].insert(pos); // important changed place should also be added to map
            mp[A[i]].insert(i);     // important add current element too
        }
    }
    
    return A;
}
