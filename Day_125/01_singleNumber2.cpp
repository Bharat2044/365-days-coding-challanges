// Question Link: https://www.interviewbit.com/problems/single-number-ii/

/*
Single Number II

Problem Description
Given an array of integers, every element appears thrice except for one, which occurs once.
 Find that element that does not appear thrice.
 NOTE: Your algorithm should have a linear runtime complexity.
 Can you implement it without using extra memory?

Problem Constraints:
2 <= A <= 5*106
0 <= A <= INTMAX

Input Format:
First and only argument of input contains an integer array A.

Output Format:
Return a single integer.

Example Input:
Input 1:
 A = [1, 2, 4, 3, 3, 2, 2, 3, 1, 1]
Input 2:
 A = [0, 0, 0, 1]

Example Output:
Output 1:
 4
Output 2:
 1

Example Explanation:
Explanation 1:
 4 occurs exactly once in Input 1.
 1 occurs exactly once in Input 2.
*/


int Solution::singleNumber(const vector<int> &A) {
    int n = A.size();
    int ans = 0;
    
    vector<int> bits(32, 0);
    for(int i = 0; i < n; i++){
        int temp = A[i];
        
        for(int j = 0; j < 32; j++){
            if(temp & 1){
            bits[j]++;
        }
            temp = temp >> 1;
        }
    }
    
    for(int i = 0; i < 32; i++){
        bits[i] = bits[i]%3;
        ans += bits[i]*(pow(2, i));
    }
    
    return ans;
}

