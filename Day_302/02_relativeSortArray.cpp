// Question Link: https://leetcode.com/problems/relative-sort-array/

/*
1122. Relative Sort Array

Given two arrays arr1 and arr2, the elements of arr2 are distinct, and all elements in arr2 are also in arr1.

Sort the elements of arr1 such that the relative ordering of items in arr1 are the same as in arr2. Elements that do not appear in arr2 should be placed at the end of arr1 in ascending order.

Example 1:
Input: arr1 = [2,3,1,3,2,4,6,7,9,2,19], arr2 = [2,1,4,3,9,6]
Output: [2,2,2,1,4,3,3,9,6,7,19]
Example 2:
Input: arr1 = [28,6,22,8,44,17], arr2 = [22,28,8,6]
Output: [22,28,8,6,17,44]
 
Constraints:
1 <= arr1.length, arr2.length <= 1000
0 <= arr1[i], arr2[i] <= 1000
All the elements of arr2 are distinct.
Each arr2[i] is in arr1.
*/



class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        unordered_map<int, int> mp1; // Create a map to count the occurrences of elements in arr1
        vector<int> ans; // Initialize a vector to store the sorted result
        vector<int> remaining; // Initialize a vector to store the remaining elements

        // Step 1: Count the occurrences of each element in arr1
        for (int i = 0; i < arr1.size(); i++) {
            mp1[arr1[i]]++;
        }
//     for(int i=0;i<arr2.size();i++)
        //     {
        //          for(auto it:mp1)
        // {
        //         if(arr2[i]==it.first)
        //         {
        //             for(int j=0;j<it.second;j++)
        //             {
        //             ans.push_back(it.first);
                
        //             }

        //         }
        //     }
        //     mp1.erase(arr2[i]);
        // }

        // Or we can use 2 loop
        // Step 2: Process elements from arr2
        for (int i = 0; i < arr2.size(); i++) {
            // For each element in arr2, add it to 'ans' as many times as it appears in arr1
            for (int j = 0; j < mp1[arr2[i]]; j++) {
                ans.push_back(arr2[i]);
            }
            // Remove the processed element from mp1 (decrement count or erase)
            mp1.erase(arr2[i]);
        }

        // Step 3: Process remaining elements in mp1
        for (auto it : mp1) {
            // For each element in mp1, add it to 'remaining' as many times as it appears in arr1
            for (int j = 0; j < it.second; j++) {
                remaining.push_back(it.first);
            }
        }

        // Step 4: Sort the 'remaining' vector
        sort(remaining.begin(), remaining.end());

        // Step 5: Concatenate 'remaining' to the end of 'ans'
        ans.insert(ans.end(), remaining.begin(), remaining.end());

        return ans; // Return the sorted result
    }
};
