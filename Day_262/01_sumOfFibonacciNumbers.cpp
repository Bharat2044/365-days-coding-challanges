// Question Link: https://www.interviewbit.com/problems/sum-of-fibonacci-numbers/

/*
Sum Of Fibonacci Numbers

Problem Description:
How many minimum numbers from the Fibonacci series are required such that the sum of numbers should be equal to a given Number A? 
Note: repetition of numbers is allowed.

Problem Constraints:
1 <= A <= 109

Input Format:
The first argument is an integer A.

Output Format:
Return an integer equal to the minimum number of Fibonacci numbers whose sum is equal to A

Example Input:
Input 1:
A = 4
Input 2:
A = 7

Example Output:
Output 1:
2
Output 2:
2

Example Explanation:
Explanation 1:
Two numbers are required, A = 4 which is equal to (2 + 2)
Explanation 2:
Two numbers are required, A = 7 which is equal to (2 + 5)
*/



int Solution::fibsum(int n) {   
    vector<int>fb;
    fb.push_back(1);
    fb.push_back(1);
   
    while(fb.back()<n)
        fb.push_back(fb.back()+fb[fb.size()-2]);
   
    set<int>s;
   
    for(auto &x:fb)
        s.insert(x);
   
    int cnt=0;
   
    while(n!=0)
    {
        auto it = s.upper_bound(n);
        it--;
        cnt++;
        n=n-(*it);
    }
    
    return cnt;   
}
