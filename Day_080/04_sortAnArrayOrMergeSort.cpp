// Question Link: https://leetcode.com/problems/sort-an-array/description/

/*
912. Sort an Array

Given an array of integers nums, sort the array in ascending order and return it.

You must solve the problem without using any built-in functions in O(nlog(n)) time complexity and with the smallest space complexity possible.

Example 1:
Input: nums = [5,2,3,1]
Output: [1,2,3,5]
Explanation: After sorting the array, the positions of some numbers are not changed (for example, 2 and 3), while the positions of other numbers are changed (for example, 1 and 5).
Example 2:
Input: nums = [5,1,1,2,0,0]
Output: [0,0,1,1,2,5]
Explanation: Note that the values of nums are not necessairly unique.
 
Constraints:
1 <= nums.length <= 5 * 104
-5 * 104 <= nums[i] <= 5 * 104
*/



class Solution {
public:

    void mergeProcedure(vector<int>& nums, int low, int mid, int high) {   // function definition of mergeProcedure
        // n1 is the size of the left subarray
        // n2 is the size of the right subarray
        int n1 = mid-low+1;
        int n2 = high-mid;

        // create leftSubarray and rightSubarray of size n1 and n2
        int leftSubarray[n1];
        int rightSubarray[n2];

        // copy the elements to left and right subarrays
        for(int i=0; i<n1; i++)
            leftSubarray[i] = nums[low + i];
        for(int j=0; j<n2; j++)
            rightSubarray[j] = nums[mid + 1 + j];

        // merging
        int i = 0, j = 0;
        int k = low;

        while(i < n1 && j < n2) {
            if(leftSubarray[i] <= rightSubarray[j])
                nums[k++] = leftSubarray[i++];
            else
                nums[k++] = rightSubarray[j++];
        }

        // copy remaining elements of leftSubarrays
        while(i < n1)
                nums[k++] = leftSubarray[i++];
                
        // copy remaining elements of rightSubarrays
        while(j < n2)
                nums[k++] = rightSubarray[j++];
    }

    void mergeSort(vector<int>& nums, int low, int high) {  // function definition of mergeSort
        // big problem
        if(low < high) {
            // divide and conquer algorithm
            // 1. divide the bigger problem into smaller subproblems
            int mid = low + (high - low) /2;

            // 2. conquer via using the recursion
            // left subarray
            mergeSort(nums, low, mid);            
            // right subarray
            mergeSort(nums, mid+1, high);

            // 3. combine the solution
            mergeProcedure(nums, low, mid, high);   // calling mergeProcedure function
        }
    }

    vector<int> sortArray(vector<int>& nums) {
        mergeSort(nums, 0, nums.size()-1);  // calling mergeSort function

        return nums;
    }
};
