// Question Link: https://www.interviewbit.com/problems/colorful-number/

/*
Colorful Number

Problem Description:
For Given Number A, find if it's a COLORFUL number or not.

COLORFUL number:
A number can be broken into different contiguous sub-subsequence parts. 
Suppose, a number 3245 can be broken into parts like 3 2 4 5 32 24 45 324 245. 
And this number is a COLORFUL number, since product of every digit of a contiguous subsequence is different
Return 1 if A is a COLORFUL number, else return 0

Problem Constraints:
0 <= A <= 109

Input Format:
The first argument is an integer A.

Output Format:
Return 1 if A is a COLORFUL number, else return 0

Example Input
A = 23

Example Output:
1

Example Explanation:
A = 23
2 3 23
2 -> 2
3 -> 3
23 -> 6
this number is a COLORFUL number since the product of every digit of a sub-sequence is different.

Output: 1
*/



int Solution::colorful(int A) {
    unordered_map<long long, int>mp;
    string s=to_string(A);
    int n=s.length();
    
    if(n==1) 
        return 1;
    
    for(int i=0;i<n;i++)
    {
        long long prod=1;
        for(int j=i;j<n;j++)
        {
            prod*=(long long)(s[j]-'0');
            if(mp.find(prod)!=mp.end())
                return 0;
            mp[prod]++;
        }
    }
    
    return 1;
}
