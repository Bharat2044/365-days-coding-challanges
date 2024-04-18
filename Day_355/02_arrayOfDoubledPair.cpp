// Question Link: https://leetcode.com/problems/array-of-doubled-pairs/

/*
954. Array of Doubled Pairs

Given an integer array of even length arr, return true if it is possible to reorder arr such that arr[2 * i + 1] = 2 * arr[2 * i] for every 0 <= i < len(arr) / 2, or false otherwise.

Example 1:
Input: arr = [3,1,3,6]
Output: false
Example 2:
Input: arr = [2,1,2,6]
Output: false
Example 3:
Input: arr = [4,-2,2,-4]
Output: true
Explanation: We can take two groups, [-2,-4] and [2,4] to form [-2,-4,2,4] or [2,4,-2,-4].
 
Constraints:
2 <= arr.length <= 3 * 10^4
arr.length is even.
-10^5 <= arr[i] <= 10^5
*/



class Solution {
public:
    bool canReorderDoubled(vector<int>& arr) {
        unordered_map<int,int> mp;
        for(int i: arr) mp[i]++;
        vector<int> k;
        for(auto x: mp) k.push_back(x.first);
        sort(k.begin(),k.end(),[](int a, int b){
            return abs(a) < abs(b);
        });
        for(int x:k){
            if(mp[x] > mp[2*x]) return false;
            mp[2*x] -= mp[x];
        }
        return true;
    }
};
