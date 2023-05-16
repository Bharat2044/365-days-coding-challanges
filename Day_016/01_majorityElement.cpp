// Question Link: https://www.interviewbit.com/problems/majority-element/

/*
Majority Element:

Problem Description:
Given an array of size N, find the majority element. The majority element is the element that appears more than floor(N/2) times.
You may assume that the array is non-empty and the majority element always exist in the array.

Problem Constraints:
1 <= |A| <= 106
1 <= Ai <= 109

Input Format:
The first argument is an integer array A.

Output Format:
Return the majority element.

Example Input:
A = [2, 1, 2]

Example Output:
2

Example Explanation:
2 occurs 2 times which is greater than 3/2.
*/


// Brute Force ==> Time Complexity = O(n^2), Space Complexity = O(1)
/*int Solution::majorityElement(const vector<int> &A) {
    
    for(int i=0; i<A.size(); i++) {
        int count = 0;
        
        for(int j=0; j<A.size(); j++) {
            if(A[i] == A[j])
                count++;
        }
        
        if(count > A.size()/2)
            return A[i];
    }
    
    return -1;
}*/



// Optimized Approach ==> Time Complexity = O(n), Space Complexity = O(1)
int Solution::majorityElement(const vector<int> &A) {
    
    int count = 0;
    int ele;
    
    for(int i=0; i<A.size(); i++) {
        
        if(count == 0) {
            count = 1;
            ele = A[i];
        }        
        else if(A[i] == ele)
            count++;
        else
            count--;
    }
    
    int count1 = 0;
    
    for(int i=0; i<A.size(); i++) {        
        if(A[i] == ele) 
            count1++;
    }
    
    return (count1 > A.size()/2) ? ele : -1;
}

