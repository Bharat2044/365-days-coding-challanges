// Question Link: https://www.interviewbit.com/problems/maximum-area-of-triangle/

/*
Maximum Area of Triangle!

Problem Description:
Given a character matrix of size N x M in the form of a string array A of size N where A[i] denotes ith row.

Each character in the matrix consists any one of the following three characters {'r', 'g', 'b'} where 'r' denotes red color similarly 'g' denotes green color and 'b' denotes blue color.
You have to find the area of the largest triangle that has one side parallel to y-axis i.e vertical and the color of all three vertices are different.

NOTE:
If the area comes out to be a real number than return the ceil of that number.

Problem Constraints:
2 <= N, M <= 103
A[i][j] = 'r' or A[i][j] = 'g' or A[i][j] = 'b'

Input Format:
First and only argument is an string array A of size N denoting the 2D character matrix.

Output Format:
Return a single integer denoting the area of the largest triangle that has one side parallel to y-axis i.e vertical and the color of all three vertices are different.
If the area comes out to be a real number than return the ceil of that number.

Example Input:
Input 1:
 A = ["rrrrr", "rrrrg", "rrrrr", "bbbbb"]
Input 2:
 A = ["rrr", "rrr", "rrr", "rrr"]

Example Output:
Output 1:
 10
Output 2:
 0

Example Explanation:
Explanation 1:
 The maximum area of triangle is 10.
 Triangle coordinates are (0,0) containing r, (1,4) containing g, (3,0) containing b.
Explanation 2:
 All cells have same color so no triangle possible so we will return 0
*/




int Solution::solve(vector<string> &A) {
    int n = A.size(), m = A[0].size();
    map<char, int> mxr[m], mnr[m], mxc, mnc;

    // Iterate through each element in the vector of strings
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            // Update the maximum row index for each character in column j
            mxr[j][A[i][j]] = max(mxr[j][A[i][j]], i);

            // Update the minimum row index for each character in column j
            if(mnr[j].count(A[i][j]))
                mnr[j][A[i][j]] = min(mnr[j][A[i][j]], i);
            else
                mnr[j][A[i][j]] = i;

            // Update the maximum column index for each character
            mxc[A[i][j]] = max(mxc[A[i][j]], j);

            // Update the minimum column index for each character
            if(mnc.count(A[i][j]))
                mnc[A[i][j]] = min(mnc[A[i][j]], j);
            else
                mnc[A[i][j]] = j;
        }
    }

    int ans = 0;

    // Iterate through each column
    for(int i = 0; i < m; i++) {
        // Check if the necessary characters exist in the respective maps
        if(mxr[i].count('r') and mxr[i].count('g') and mxc.count('b'))
            ans = max(ans, max(abs(mxr[i]['r'] - mnr[i]['g']) + 1, abs(mxr[i]['g'] - mnr[i]['r']) + 1) * max(abs(mxc['b'] - i) + 1, abs(i - mnc['b']) + 1));
        if(mxr[i].count('g') and mxr[i].count('b') and mxc.count('r'))
            ans = max(ans, max(abs(mxr[i]['g'] - mnr[i]['b']) + 1, abs(mxr[i]['b'] - mnr[i]['g']) + 1) * max(abs(mxc['r'] - i) + 1, abs(i - mnc['r']) + 1));
        if(mxr[i].count('r') and mxr[i].count('b') and mxc.count('g'))
            ans = max(ans, max(abs(mxr[i]['r'] - mnr[i]['b']) + 1, abs(mxr[i]['b'] - mnr[i]['r']) + 1) * max(abs(mxc['g'] - i) + 1, abs(i - mnc['g']) + 1));
    }

    return (ans + 1) / 2;
}
