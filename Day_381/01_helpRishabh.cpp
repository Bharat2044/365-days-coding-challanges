// Question Link: https://www.interviewbit.com/problems/help-rishabh/

/*
Help Rishabh!

Problem Description:
Rishabh and Ojas are on a mission. Their is a bomb which they want to diffuse but the problem is they have to solve a task first which is very difficult for them.
As you are their friend, they ask you to solve the problem for them.
Given an integer array A containing N integers.
You need to find the total number of Scaler Subarrays in A.
A subarray is called Scaler Subarray if there are exactly B elements in the subarray which occurs atleast 2 times.

Problem Constraints:
1 <= N <= 10^5
1 <= A[i] <= 10^3
1 <= B <= N

Input Format:
First argument is an integer array A.
Second argument is an integer B.

Output Format:
Return an integer denoting the total number of Scaler Subarrays in A.
NOTE: It is guaranteed that the output never exceeds the INTEGER 32 Bit range.

Example Input:
Input 1:
 A = [1, 2, 3, 1, 2, 3]
 B = 2
Input 2:
 A = [1, 1, 1, 2, 2]
 B = 1

Example Output:
Output 1:
 2
Output 2:
 7

Example Explanation:
Explanation 1:
 There are only two Scaler Subrrays
 1. A[0:4] i.e [1, 2, 3, 1, 2] as 1 and 2 only have occurences greater than or equal to 2
 2. A[1:5] i.e [2, 3, 1, 2, 3] as 2 and 3 only have occurences greater than or equal to 2 
*/



int fun(vector < int > & a, int b) {
    int n = a.size();
    int ans = 0;
    int countOcc[1005] = {0};
    int occ = 0;
    int r = -1;
    for(int i = 0; i < n; i++) {
        while(r + 1 < n){
            if(countOcc[a[r + 1]] == 1 and occ == b)
                break;
            r++;
            countOcc[a[r]]++;
            if(countOcc[a[r]] == 2)
                occ++;
        } 
        ans += (r - i + 1);
        countOcc[a[i]]--;
        if(countOcc[a[i]] == 1)
            occ--;
    }
    return ans;
}

int Solution::solve(vector < int > & A, int B) {
    return fun(A, B) - fun(A, B - 1);
}
