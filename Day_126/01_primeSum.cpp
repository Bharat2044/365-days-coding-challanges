// Question Link: https://www.interviewbit.com/problems/prime-sum/

/*
Prime Sum

Problem Description:
Given an even number ( greater than 2 ), return two prime numbers whose sum will be equal to the given number.
If there is more than one solution possible, return the lexicographically smaller solution i.e.
If [a, b] is one solution with a <= b,
and [c,d] is another solution with c <= d, then

[a, b] < [c, d] 
If a < c OR ( a == c AND b < d ).
NOTE: A solution will always exist. read Goldbach's conjecture

Problem Constraints:
1 <= A <= 2 * 107

Input Format:
The first argument is an integer A.

Output Format:
Return an array of integers.

Example Input:
4

Example Output:
[2, 2]

Example Explanation:
2 + 2 equals 4, which is the lexicographically smaller solution
*/



bool isprime(int a)
{
   
    vector<int>v;
    for(int i=1;i<=a;i++)
    {
        if(a%i==0)
        {
           
            v.push_back(i);
        }
    }
    vector<int>v1;
    v1.push_back(1);
    v1.push_back(a);
    if(v==v1)
    {
        return true;
    }
    else
    {
        return false;
    }
     
}
vector<int> Solution::primesum(int A)
{
    vector<int>ans;
    for(int i=2;i<A;i++)
    {
        for(int j=2;j<A;j++)
        {
            if((i+j)==A)
            {
                if(isprime(i) && isprime(j))
                {
                    ans.push_back(i);
                    ans.push_back(j);
                    return ans;
                }
               
            }
        }
    }
    return ans;
}
