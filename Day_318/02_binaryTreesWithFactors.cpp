// Question Link: https://leetcode.com/problems/binary-trees-with-factors/

/*
823. Binary Trees With Factors

Given an array of unique integers, arr, where each integer arr[i] is strictly greater than 1.
We make a binary tree using these integers, and each number may be used for any number of times. Each non-leaf node's value should be equal to the product of the values of its children.
Return the number of binary trees we can make. The answer may be too large so return the answer modulo 109 + 7.

Example 1:
Input: arr = [2,4]
Output: 3
Explanation: We can make these trees: [2], [4], [4, 2, 2]
Example 2:
Input: arr = [2,4,5,10]
Output: 7
Explanation: We can make these trees: [2], [4], [5], [10], [4, 2, 2], [10, 2, 5], [10, 5, 2].
 
Constraints:
1 <= arr.length <= 1000
2 <= arr[i] <= 109
All the values of arr are unique.
*/



class Solution {
public:
    int numFactoredBinaryTrees(vector<int>& arr) {
        const int mod =1e9+7;
        sort(arr.begin(), arr.end());
        unordered_map<int, long long> mp;
        long long ans = 0;

        for (int x: arr) {
            mp[x]=1;
            int sqrt_x=sqrt(x);

            #pragma unroll
            for (int j=0;  arr[j]<=sqrt_x; j++){
                int y=arr[j];
                if (x % y == 0){
                    int z=x/y;
                    int c=(y==z)?1:2;
                    if (mp.count(z))// Add this faster
                        mp[x]=(mp[x]+mp[y]*mp[z]*c)%mod;
                }
                   
            }
                
            ans = (ans + mp[x]) % mod;
        }
        return ans;
    }
};
