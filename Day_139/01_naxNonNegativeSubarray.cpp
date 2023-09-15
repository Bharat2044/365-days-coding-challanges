// Question Link: https://www.interviewbit.com/problems/max-non-negative-subarray/

/*
Max Non Negative SubArray

Problem Description
Given an array of integers, A of length N, find out the maximum sum sub-array of non negative numbers from A.

The sub-array should be contiguous i.e., a sub-array created by choosing the second and fourth element and skipping the third element is invalid.

Maximum sub-array is defined in terms of the sum of the elements in the sub-array.

Find and return the required subarray.

NOTE:  
If there is a tie, then compare with segment's length and return segment which has maximum length.
If there is still a tie, then return the segment with minimum starting index.

Problem Constraints:
1 <= N <= 105
-109 <= A[i] <= 109

Input Format:
The first and the only argument of input contains an integer array A, of length N.

Output Format:
Return an array of integers, that is a subarray of A that satisfies the given conditions.

Example Input:
Input 1:
 A = [1, 2, 5, -7, 2, 3]
Input 2:
 A = [10, -1, 2, 3, -4, 100]

Example Output:
Output 1:
 [1, 2, 5]
Output 2:
 [100]

Example Explanation:
Explanation 1:
 The two sub-arrays are [1, 2, 5] [2, 3].
 The answer is [1, 2, 5] as its sum is larger than [2, 3].
Explanation 2:
 The three sub-arrays are [10], [2, 3], [100].
 The answer is [100] as its sum is larger than the other two.
*/



vector<int> Solution::maxset(vector<int> &A) {
    vector<pair<vector<int>,long long int>> p;
    int index=0,i;
    long long int sum=-1;

    while(index<A.size()){
        vector<int> subarray;
        sum=0;

        for(i=index;A[i]>=0;i++){
            subarray.push_back(A[i]);
            sum+=A[i];
            if(i==A.size()-1) break;
        }

        index=i;
        p.push_back(make_pair(subarray,sum));
        index++;
    }

    long long int max=0;
    int ind=0;

    for(int j=0; j<p.size(); j++){
        if(p[j].second>max){
            max=p[j].second;
            ind=j;
        }
    }

    return p[ind].first;
}
