// Question Link: https://www.interviewbit.com/problems/fraction/

/*
Fraction

Problem Description:
Given two integers representing the numerator and denominator of a fraction, return the fraction in string format.
If the fractional part is repeating, enclose the repeating part in parentheses.

Problem Constraints:
INTMIN <= A, B <= INTMAX

Input Format:
The first integer A represents the numerator.
The second integer B represents the denominator.

Output Format:
Return a string

Example Input:
Input 1:
A = 1
B = 2
Input 2:
A = 2
B = 1
Input 3:
A = 2
B = 3

Example Output:
Output 1:
"0.5"
Output 2:
"2"
Output 3:
"0.(6)"

Example Explanation:
Explanation 1:
Given numerator = 1, denominator = 2, return "0.5"
Explanation 1:
Given numerator = 2, denominator = 1, return "2"
Explanation 1:
Given numerator = 2, denominator = 3, return "0.(6)"
*/



string Solution::fractionToDecimal(int A, int B) {
    string ans="";
    long long int num=A;
    long long int den=B;
    
    if(num>0 && den<0)
    {
        ans+='-';
    }
    else if(num<0 && den>0)
    {
        ans+='-';
    }
    
    num=abs(num);
    den = abs(den);
    
    if(num==0)
    {
        return "0";
    }
    
    long long int r=num%den;
    long long int v=num/den;
    ans+=to_string(v);
    map<long long int,long long int>m;
    
    if(r!=0)
    {
        ans+='.';
        while(1)
        {
            if(m.find(r)!=m.end())
            {
                return ans.substr(0,m[r])+'('+ans.substr(m[r])+')';
                break;
            }
            if(r==0)
            {
                return ans;
                break;
            }
            m[r]=ans.size();
            long long int d= (r*10)/den;
            ans+=to_string(d);
            r=(r*10)%den;
        }
    }
    
    return ans;
}
