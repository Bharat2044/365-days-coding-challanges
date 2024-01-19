// Question Link: https://www.interviewbit.com/problems/super-array/

/*
Super Array

Problem Description:
Robin found an array A of size N which he wants to convert into super array.
To do this he decided to choose first or last element do one of the following operation with equal probability B times.
Delete the chosen element.
Increment the chosen element by one.
After performing all operations, if the array consist of atleast C elements greater than the special value of array then the array is called super array.
Special value is the bitwise XOR of all elements.
Find and return the total number of possible super array, he can get by performing the above operations.

Problem Constraints:
1 <= N <= 10
1 <= A[i] <= 109
1 <= B, C <= N

Input Format:
First argument is an integer array A of size N.
Second argument is an integer B.
Third argument is an integer C.

Output Format:
Return an integer denoting the possible number of super array.

Example Input:
Input 1:
 A = [10, 2, 10, 5]
 B = 3
 C = 3
Input 2:
 A = [3, 3, 4]
 B = 3
 C = 2

Example Output:
Output 1:
1
Output 2:
3
 
Example Explanation:
Explanation 1:
 Special value will be 7.
 There will be only one possible super array: [10, 2, 10, 8]. 
 Perform three operation by incrementing last element.
Explanation 2:
 There will be 3 possible super array.
*/



int ans = 0;
void recur(vector<int> &A, int B, int C, int val){
    if(B == 0){
        int cnt = 0;
        for(int i = 0; i < A.size(); i++){
            if(A[i] > val){
                cnt++;
            }
        }
        if(cnt >= C){
            ans++;
        }
        return;
    }
    int temp = A[0];
    // delete first element
    A.erase(A.begin());
    recur(A, B-1, C, val);
    A.insert(A.begin(), temp);

    // delete last element
    temp = A.back();
    A.pop_back();
    recur(A, B-1, C, val);
    A.push_back(temp);

    // Increment first element
    A[0]++;
    recur(A, B-1, C, val);
    A[0]--;

    // Increment last element
    A[A.size()-1] ++;
    recur(A, B-1, C, val);
    A[A.size()-1] --;
}


int Solution::solve(vector<int> &A, int B, int C) {
    int n = A.size();
    int val = 0;
    ans = 0;
    for(int i = 0; i < n; i++){
        val = val^A[i];
    }
    recur(A, B, C, val);
    return ans;
}

