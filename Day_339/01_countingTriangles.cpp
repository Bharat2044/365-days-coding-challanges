// Question Link: https://www.interviewbit.com/problems/counting-triangles/

/*
Counting Triangles

Problem Description:
You are given an array of N non-negative integers, A0, A1,..., AN-1.
Considering each array element Ai as the edge length of some line segment, count the number of triangles that you can form using these array values.

Notes:
You can use any value only once while forming each triangle. The order of choosing the edge lengths doesn't matter. Any triangle formed should have a positive area.
Return answer modulo 109 + 7.

Problem Constraints:
1 <= |A| <= 10^3
0 <= Ai <= 10^6

Input Format:
The first argument is an integer array A.

Output Format:
Return an integer equal to the count of the number of triangles that you can form.

Example Input:
A = [1, 1, 1, 2, 2]

Example Output:
4
*/



int Solution::nTriang(vector<int> &A) {
    int n = A.size(), ctr = 0;

    const int M = 1e9 + 7;
    sort(A.begin(), A.end());

    for(int i=n-1; i>=2; i--){
        int l = 0, r = i-1; 

        while(l < r){
            int sum = A[l] + A[r];

            if(sum > A[i]){
                ctr = (ctr % M) + ((r-l)%M);
                r--;
            }

            else 
                l++;
        }
    }

    return ctr;
}
