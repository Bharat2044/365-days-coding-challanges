// Question Link: https://www.interviewbit.com/problems/maximum-unsorted-subarray/

/*
Maximum Unsorted Subarray

Problem Description:
Given an array A of non-negative integers of size N. Find the minimum sub-array Al, Al+1 ,..., Ar such that if we sort(in ascending order) that sub-array, then the whole array should get sorted.
If A is already sorted, output -1.

Problem Constraints:
1 <= N <= 1000000
1 <= A[i] <= 1000000

Input Format:
First and only argument is an array of non-negative integers of size N.

Output Format:
Return an array of length two where the first element denotes the starting index(0-based) and the second element denotes the ending index(0-based) of the sub-array. If the array is already sorted, return an array containing only one element i.e. -1.

Example Input:
Input 1:
A = [1, 3, 2, 4, 5]
Input 2:
A = [1, 2, 3, 4, 5]

Example Output:
Output 1:
[1, 2]
Output 2:
[-1]

Example Explanation:
Explanation 1:
If we sort the sub-array A1, A2, then the whole array A gets sorted.
Explanation 2:
A is already sorted.
*/





vector<int> Solution::subUnsort(vector<int> &A) {
    vector<int> B;
    int st, end=-1;
    B = A;
    
    for(int i = 0; i<B.size()-1 ; i++)
    {
        if(B[i] > B[i+1]){
            int temp = B[i];
            B[i]=B[i+1];
            B[i+1] = temp;
        }
    }
    
    for(int i = A.size()-1; i>=0 ; i--)
    {
        if(B[i] != A[i])
        {
            end = i;
            break;
        }
    }
    
    if(end == -1)
    {
        return {-1};
    }
    
    B=A;
    
    for(int i=B.size()-1; i>0; i--)
    {
        if(B[i]<B[i-1])
        {
            int temp = B[i];
            B[i] = B[i-1];
            B[i-1] = temp;
        }
    }
    
    for(int i = 0; i<A.size() ; i++)
    {
        if(B[i] != A[i])
        {
            st=i;
            break;
        }
    }
    
    return {st, end};
}
