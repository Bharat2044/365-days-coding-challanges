// Question Link: https://www.interviewbit.com/problems/longest-arithmetic-progression/

/*
Longest Arithmetic Progression

Problem Description:
Find the longest Arithmetic Progression in an integer array A of size N, and return its length.

More formally, find longest sequence of indices, 0 < i1 < i2 < … < ik < ArraySize(0-indexed) such that sequence A[i1], A[i2], …, A[ik] is an Arithmetic Progression.

Arithmetic Progression is a sequence in which all the differences between consecutive pairs are the same, i.e sequence B[0], B[1], B[2], …, B[m - 1] of length m is an Arithmetic Progression if and only if B[1] - B[0] == B[2] - B[1] == B[3] - B[2] == … == B[m - 1] - B[m - 2]

Note: The common difference can be positive, negative, or 0.

Problem Constraints:
1 <= N <= 1000
1 <= A[i] <= 1e9

Input Format:
The first and only argument of input contains an integer array, A.

Output Format:
Return an integer, representing the length of the longest possible arithmetic progression.

Example Input:
Input 1:
 A = [3, 6, 9, 12]
Input 2:
 A = [9, 4, 7, 2, 10]

Example Output:
Output 1:
4
Output 2:
3

Example Explanation:
Explanation 1:
[3, 6, 9, 12] form an arithmetic progression.
Explanation 1:
[4, 7, 10] form an arithmetic progression.
*/




int Solution::solve(const vector<int> &A) {

	int n = A.size();

	if (n < 3) return n;

	vector<vector<int> > dp(n, vector<int>(n, -1));

	map<int, int> pos;

	for (int i = 0; i < n; i++) {

		for (int j = i + 1; j < n; j++) {

			dp[i][j] = 2;

			int dif = A[j] - A[i];

			int need = 2 * A[i] - A[j];

			if (pos.count(need) == 0) continue;

			dp[i][j] = max(dp[i][j], dp[pos[need]][i] + 1);

		}
		pos[A[i]] = i;

	}

	int ans = 2;

	for (int i = 0; i < n; i++) {

		for (int j = i + 1; j < n; j++) {

			ans = max(ans, dp[i][j]);

		}

	}

	return ans;
}


//it’s O(n ^ 2 * log(n)) solution. 
//Also we can use unordered map(hash map) here,
// but its running time is undetermined
//(it's **O(1)** in average, but constant might be too big).

