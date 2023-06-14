// Question Link: https://www.interviewbit.com/problems/find-duplicate-in-array/

/*
Find Duplicate in Array

Problem Description:
Given a read-only array of n + 1 integers between 1 and n, find one number that repeats in linear time using less than O(n) space and traversing the stream sequentially O(1) times.
If there are multiple possible answers ( like in the sample case ), output any one, if there is no duplicate, output -1

Problem Constraints:
1 <= |A| <= 105
1 <= Ai <= |A|

Input Format:
The first argument is an integer array A.

Output Format:
Return the integer that repeats in array A

Example Input:
Input 1:
A = [3, 4, 1, 4, 2]
Input 2:
A = [1, 2, 3]
Input 3:
A = [3, 4, 1, 4, 1]

Example Output:
Output 1:
4
Output 2:
-1
Output 3:
1

Example Explanation:
Explanation 1:
4 repeats itself in the array [3, 4, 1, 4, 2]
Explanation 2:
No number repeats itself in the array [1, 2, 3]
Explanation 3:
1 and 4 repeats itself in the array [3, 4, 1, 4, 1], we can return 1 or 4
*/



int Solution::repeatedNumber(const vector<int> &A) {
    int n = A.size(); //elements will be bt 1 to n-1
    
    vector<int> freq(n+1, 0);
    int rep;
    
    for(int i=0; i<n; i++) {
        
        if(freq[A[i]] == 0)
            freq[A[i]]++;
        else 
            rep = A[i];
    }
    
    return rep;
}
