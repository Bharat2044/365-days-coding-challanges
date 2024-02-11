// Question Link: https://www.interviewbit.com/problems/magician-and-chocolates/

/*
Magician and Chocolates

Problem Description:
Given N bags, each bag contains Bi chocolates. There is a kid and a magician. In one unit of time, kid chooses a random bag i, eats Bi chocolates, then the magician fills the ith bag with floor(Bi/2) chocolates.
Find the maximum number of chocolates that kid can eat in A units of time.

NOTE: 
floor() function returns the largest integer less than or equal to a given number.
Return your answer modulo 109+7

Problem Constraints:
1 <= A <= 105
1 <= |B| <= 105
1 <= Bi <= INT_MAX

Input Format:
First argument is an integer A.
Second argument is an integer array B of size N.

Output Format:
Return an integer denoting the maximum number of chocolates that kid can eat in A units of time.

Example Input:
Input 1:
A = 3
B = [6, 5]
Input 2:
A = 5
b = [2, 4, 6, 8, 10]

Example Output:
Output 1:
14
Output 2:
33

Example Explanation:
Explanation 1:
 At t = 1 kid eats 6 chocolates from bag 0, and the bag gets filled by 3 chocolates. 
 At t = 2 kid eats 5 chocolates from bag 1, and the bag gets filled by 2 chocolates. 
 At t = 3 kid eats 3 chocolates from bag 0, and the bag gets filled by 1 chocolate. 
 so, total number of chocolates eaten are 6 + 5 + 3 = 14
*/



int Solution::nchoc(int A, vector<int> &B) {
   
    priority_queue<int> p;
    long long int total = 0;
   
    for (int i = 0; i < B.size(); i++)
        p.push(B[i]);
   
    while (A > 0 && !p.empty()) {
        total = (total + p.top()) % 1000000007; // You should use % 1000000007 here
        if (p.top() / 2 > 0) // Check if the division result is greater than 0 before pushing
            p.push(p.top() / 2);
        p.pop();
        A--;
    }
   
    return total;
}
