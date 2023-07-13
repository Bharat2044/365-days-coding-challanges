// Question Link: https://www.interviewbit.com/problems/max-rectangle-in-binary-matrix/

/*
Max Rectangle in Binary Matrix

Given a 2D binary matrix filled with 0’s and 1’s, find the largest rectangle containing all ones and return its area.

Bonus if you can solve it in O(n^2) or less.

Example :
Input:
A : [  1 1 1
       0 1 1
       1 0 0 
    ]
Output : 4 

As the max area rectangle is created by the 2x2 rectangle created by (0,1), (0,2), (1,1) and (1,2)
*/



int Solution::maximalRectangle(vector<vector<int> > &A) {
    int n = A.size();
    if (n == 0) return 0;
    int m = A[0].size();
    if (m == 0) return 0;

    vector<int> left(m, 0), right(m, m - 1), height(m, 0);
    int max_area = 0;

    for (int i = 0; i < n; i++) {
        int cur_left = 0, cur_right = m - 1;
        for (int j = 0; j < m; j++) {
            if (A[i][j] == 1) height[j]++;
            else height[j] = 0;
        }
        for (int j = 0; j < m; j++) {
            if (A[i][j] == 1) left[j] = max(left[j], cur_left);
            else {
                left[j] = 0;
                cur_left = j + 1;
            }
        }
        for (int j = m - 1; j >= 0; j--) {
            if (A[i][j] == 1) right[j] = min(right[j], cur_right);
            else {
                right[j] = m - 1;
                cur_right = j - 1;
            }
        }
        for (int j = 0; j < m; j++) {
            max_area = max(max_area, (right[j] - left[j] + 1) * height[j]);
        }
    }
    return max_area;
}



