// Question Link: https://www.interviewbit.com/problems/remove-duplicates-from-sorted-array-ii/

/*
Remove Duplicates from Sorted Array II

Problem Description:
Remove Duplicates from the Sorted Array
Given a sorted array, remove the duplicates in place such that each element can appear atmost twice and return the new length.
Do not allocate extra space for another array, you must do this in place with constant memory.
Note that even though we want you to return the new length, make sure to change the original array as well in place

Problem Constraints:
1 <= |A| <= 106
1 <= Ai <= 2 * 109

Input Format:
The first argument is an integer array A.

Output Format:
Update the array and return the length of the updated array

Example Input:
A = [1,1,1,2]

Example Output:
3

Example Explanation:
For example, Given input array A = [1,1,1,2],
Your function should return length = 3, and A is now [1,1,2].
*/



int Solution::removeDuplicates(vector<int> &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    map<int,int> m;
    
    for(int i=0;i<A.size();i++)
        m[A[i]]++;
    
    for(auto i:m) {
        if(i.second > 2)
            m[i.first] = 2;
    }
    
    A.clear();

    for(auto i:m) {
        for(int j = 0; j<i.second ;j++)
            A.push_back(i.first);
    }

    return A.size();
}
