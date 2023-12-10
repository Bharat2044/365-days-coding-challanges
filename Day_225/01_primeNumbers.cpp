// Question Link: https://www.interviewbit.com/problems/prime-numbers/

/*
Prime Numbers

Problem Description:
Given a number A, find all prime numbers up to A (A included).
Make sure the returned array is sorted.

Problem Constraints:
1 <= A <= 106

Input Format:
The first argument is an integer A.

Output Format:
Return array of integers.

Example Input:
A = 7

Example Output:
[2, 3, 5, 7]

Example Explanation:
All primes till 7 are, 2, 3, 5 and 7
*/



vector<int> Solution::sieve(int A) 
{
    int n=A;
    int i,j;
    
    vector<bool>v(n+1);
    vector<int>m;
    for(i=0;i<=n;i++)
        v[i]=true;
    for(i=2;i<=n;i++)
    {
        if(v[i])
        {
            m.push_back(i);
            for(j=2;i*j<=n;j++)
            {
                //if(j!=i)
                    v[i*j]=false;
            }
        }
    }
    //free(v);
    return m;
} 
