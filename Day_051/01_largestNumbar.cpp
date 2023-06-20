// Question Link: https://www.interviewbit.com/problems/largest-number/

/*
Largest Number

Problem Description:
Given a list of non-negative integers, arrange them such that they form the largest number.
Note: The result may be very large, so you need to return a string instead of an integer.

Problem Constraints:
1 <= |A| <= 105
0 <= Ai <= 109

Input Format:
The first argument is an integer array A.

Output Format:
Return a string representing the largest number formed

Example Input:
A = [3, 30, 34, 5, 9]

Example Output:
9534330

Example Explanation:
Largest possible number that can be formed is 9534330
*/



bool comp(string A , string B){
    return A+B > B+A;
}

string Solution::largestNumber(const vector<int> &A) {
    vector<string> v;
    int n = A.size();
    
    for(int i=0; i<n; i++)
        v.push_back(to_string(A[i]));
    
    sort(v.begin(), v.end(), comp);
    string res = "";
    
    for(int i=0; i<n; i++)
        res += v[i];
    
    if(v[0] == "0")
        return "0";
        
    return res; 
}
