// Question Link: https://leetcode.com/problems/top-k-frequent-elements/

/*
347. Top K Frequent Elements

Given an integer array nums and an integer k, return the k most frequent elements. You may return the answer in any order.

Example 1:
Input: nums = [1,1,1,2,2,3], k = 2
Output: [1,2]
Example 2:
Input: nums = [1], k = 1
Output: [1]
 
Constraints:
1 <= nums.length <= 105
-104 <= nums[i] <= 104
k is in the range [1, the number of unique elements in the array].
It is guaranteed that the answer is unique.
 
Follow up: Your algorithm's time complexity must be better than O(n log n), where n is the array's size.
*/



class Solution {
public:
    int partition(vector<pair<int, int>>& vec, int l, int r) {
        int pivot = vec[r].first;  // Pivot value should be the frequency
        int j = l - 1;

        for (int i = l; i < r; i++) {
            if (vec[i].first > pivot) { 
                j++;
                swap(vec[i], vec[j]);
            }
        }

        swap(vec[j + 1], vec[r]);
        return j + 1;
    }

    void quickSelect(vector<pair<int, int>>& vec, int l, int r, int k) {
        if (l < r) {
            int part = partition(vec, l, r);
            if (part == k) {
                return;
            } else if (part < k) {
                quickSelect(vec, part + 1, r, k);
            } else {
                quickSelect(vec, l, part - 1, k);
            }
        }
    }

    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> res;
        int n = nums.size();
        unordered_map<int, int> mp;

        for (int i = 0; i < n; i++) {
            mp[nums[i]]++;
        }

        vector<pair<int, int>> vec;
        for (auto x : mp) {
            vec.push_back({x.second, x.first});
        }

        quickSelect(vec, 0, vec.size() - 1, k - 1);

        for (int i = 0; i < k; i++) {
            res.push_back(vec[i].second);
        }

        return res;
    }
};
