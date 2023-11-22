// Question Link: https://www.interviewbit.com/problems/power-of-2/

/*
Power of 2

Problem Description:
Find if the given number is a power of 2 or not. More specifically, find if the given number can be expressed as 2^k where k >= 1.
Note: The number length can be more than 64, which means the number can be greater than 2 ^ 64 (out of long long range)

Problem Constraints:
1 <= |A| <= 104

Input Format:
The first argument is a string A.

Output Format:
Return 1 if the number is a power of 2 else return 0

Example Input:
128

Example Output:
1

Example Explanation:
128 can be expressed as 2 ^ 7.
*/



int Solution::power(string A) {
    string b="2";
    reverse(A.begin(),A.end());
    
    while(b.size()<=A.size())
    {
        if(b==A)
            return 1;
        int carr=0;
        
        for(int i=0;i<b.size();i++)
        {
            int x=b[i]-'0';
            int y=x*2+carr;
            
            if(y>=10)
                carr=1;
            else
                carr=0;
            
            char r='0'+(y%10);
            b[i]=r;
        }
        
        if(carr)
            b.push_back('1');
    }
    
    return (b==A);
}
