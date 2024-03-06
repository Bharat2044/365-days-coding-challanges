// Question Link: https://interviewbit.com/problems/stringoholics/

/*
Stringoholics

Problem Description:

You are given an array A consisting of strings made up of the letters 'a' and 'b' only.
Each string goes through a number of operations, where:
1.  At time 1, you circularly rotate each string by 1 letter.
2.  At time 2, you circularly rotate the new rotated strings by 2 letters.
3.  At time 3, you circularly rotate the new rotated strings by 3 letters.
4.  At time i, you circularly rotate the new rotated strings by i % length(string) letters.

Eg: String is "abaa"
At time 1, string is "baaa", as 1 letter is circularly rotated to the back
At time 2, string is "aaba", as 2 letters of the string "baaa" is circularly rotated to the back
At time 3, string is "aaab", as 3 letters of the string "aaba" is circularly rotated to the back
At time 4, string is again "aaab", as 4 letters of the string "aaab" is circularly rotated to the back

At time 5, string is "aaba", as 1 letters of the string "aaab" is circularly rotated to the back
After some units of time, a string becomes equal to its original self.
Once a string becomes equal to itself, it's letters start to rotate from the first letter again (process resets). So, if a string takes t time to get back to the original, at time t+1 one letter will be rotated and the string will be its original self at 2t time.
You have to find the minimum time, where maximum number of strings are equal to their original self.
As this time can be very large, give the answer modulo 109+7.

Note: Your solution will run on multiple test cases so do clear global variables after using them.

Problem Constraints:
1 <= |A| <= 100

Input Format:
A: Array of strings.

Output Format:
Minimum time, where maximum number of strings are equal to their original self.

Example Input:
Input 1:
A: [a, ababa, aba]
Input 2:
A : [a, aa]

Example Output:
Output 1:
4
Output 2:
1
  
Example Explanation:
Explanation 1:
String 'a' is it's original self at time 1, 2, 3 and 4.
String 'ababa' is it's original self only at time 4. (ababa => babaa => baaba => babaa => ababa)
String 'aba' is it's original self at time 2 and 4. (aba => baa => aba)
Hence, 3 strings are their original self at time 4.
Explanation 2:
Both strings are their original self at time 1.
*/



public class Solution {
   
final static int mod = 1000000007;
 

    public int solve(String[] A) {
        int n=A.length;
        long arr[]=new long[n];
        for(int i=0;i<arr.length;i++)
        arr[i]=(long)findTime(A[i]);
        
        //System.out.println(Arrays.toString(arr));
       long ans=1;
        for(int i=0;i<arr.length;i++){
        for(int j=i+1;j<arr.length && arr[i]!=1 ;j++){
            arr[j] = arr[j]/__gcd(arr[j], arr[i]);
        }
        ans = (ans%mod*(arr[i])%mod)%mod;
    }
    return (int)ans%mod;
    }
    static long __gcd(long a, long b) 
  { 
    return b == 0? a:__gcd(b, a % b);    
  }
    public int findTime(String str)
    {
        int n=str.length();
        int k=findSmallest(str);
        for(int i=1;i<=2*n;i++)
        {
            if((long)((long)i*(i+1)/2)%(long)k==0)
            return i;
        }
        return -1;
    }
     int findSmallest(String s) {
        int n=s.length();
        int lps[]=new int[n];
        lps[0]=0;
        int len=0;
        int i=1;
        while(i<n)
        {
            if(s.charAt(len)==s.charAt(i))
            {
                len++;
                lps[i]=len;
                i++;
            }
            else
            {
                if(len==0)
                {
                    lps[i]=0;i++;
                }
                else
                {
                    len=lps[len-1];
                }
            }
        }
        int t1 = lps[n-1];
        int t2 = n-t1;
        if(t1 < t2) return n;
        else if(t1 % t2 != 0) return n;
        else return t2;
        }
    }
    


