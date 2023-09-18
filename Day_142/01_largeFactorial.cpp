// Question Link: https://www.interviewbit.com/problems/large-factorial/

/*
Large Factorial
Programming
Arrays
Medium
38.3% Success

144

16

Bookmark
Asked In:
Problem Description:
Given a number A. Find the fatorial of the number.

Problem Constraints:
1 <= A <= 100

Input Format:
First and only argument is the integer A.

Output Format:
Return a string, the factorial of A.

Example Input:
Input 1:
A = 2
Input 2:
A = 3

Example Output:
Output 1:
 2
Output 2:
 6

Example Explanation:
Explanation 1:
2! = 2 .
Explanation 2:
3! = 6 .
*/




#include<bits/stdc++.h>

string Solution::solve(int a) {
    //This vector is going to store the numbers in from 0-9 in each block

    vector<int> v(1);
    v[0]=1;
    int x=2;

    while(x<=a){
        int carry=0;

        //This for loop multiple the elements with next number
        for(int i=0;i<v.size();i++){
            int temp=v[i]*x+carry;
            v[i] = temp%10;
            carry = temp/10;
        }

        //This will store carry into the next vector location
        while(carry>0){
            v.push_back(carry%10);
            carry/=10;
        }

        x++;
    }

    //ostringstream is used to convert vector into string in best time comlexity

    ostringstream s;
    reverse(v.begin(), v.end());
    
    if (!v.empty()) {
        std::copy(v.begin(), v.end() - 1,ostream_iterator<int>(s, ""));
        s << v.back();
    }

    return s.str();
}
