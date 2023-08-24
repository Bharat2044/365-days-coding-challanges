// Question Link: https://www.interviewbit.com/problems/min-xor-value/

/*
Min XOR value
Programming
Bit Manipulation

Given an integer array A of N integers, find the pair of integers in the array which have minimum XOR value. Report the minimum XOR value.

Input Format:
    First and only argument of input contains an integer array A
Output Format:
    return a single integer denoting minimum xor value
Constraints:
2 <= N <= 100 000  
0 <= A[i] <= 1 000 000 000

For Examples :
Example Input 1:
    A = [0, 2, 5, 7]
Example Output 1:
    2
Explanation:
    0 xor 2 = 2
Example Input 2:
    A = [0, 4, 7, 9]
Example Output 2:
    3
  */



int Solution::findMinXor(vector<int> &v) {
    sort(v.begin(), v.end());
    
    int ans = INT_MAX;

    for(int i=0 ; i<v.size()-1; i++)
        ans = min(ans,v[i]^v[i+1]);

    return ans;
}

