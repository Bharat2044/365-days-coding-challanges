// Question Link: https://www.interviewbit.com/problems/prime-calculations/

/*
Prime calculations

Problem Description:
Robin's mathematic's teacher gives him some homework:
Given an integer array A of size N. For each subarray of size B, find the leftmost number with the maximum number of distinct prime factors.
You are asked to return the sum of all such numbers. Since the answer may be large return answer % 109 + 7.

Problem Constraints:
1 <= N <= 10^6
1 <= A[i] <= 10^6
1 <= B <= N

Input Format:
First argument is an integer array A of size N.
Second argument is an integer B.

Output Format:
Return an integer denoting the sum of numbers with the maximum number of distinct prime factors for each subarray of size B.

Example Input:
Input 1:
 A = [10, 2, 1, 1, 2]
 B = 3
Input 2:
 A = [18, 36, 15, 210]
 B = 2

Example Output:
Output 1:
 14
Output 2:
 264

Example Explanation:
Explanation 1:
 Subarray of size 3 are:
 (10, 2, 1) -> 10 is the leftmost element which has maximum distinct prime factors, i.e 2.
 (2, 1, 1) -> 2 is the leftmost element which has maximum distinct prime factors, i.e 1.
 (1, 1, 2) -> 2 is the leftmost element which has maximum distinct prime factors, i.e 1.
Explanation 2:
 Total sum will be 264 i.e (18 + 36 + 210)
*/



public class Solution {
    int m=(int)1e9+7;
    class Pair{
        int ele;
        int cnt;
        Pair(int ele, int cnt){
            this.ele=ele;
            this.cnt=cnt;
        }
    }
    public int solve(int[] A, int B) {
        int max=1000001;
        int spf[]= new int[max];
        spf[1]=1;
        for(int i=2;i<max;i++) spf[i]=i;
        for(int i=4;i<max;i+=2) spf[i]=2;
        for(int i=3;i*i<max;i++){
            if(spf[i]==i){
                for(int j=i*i;j<max;j+=i){
                    if(spf[j]==j)
                    spf[j]=i;
                }
            }
        } 
        
        int a[]= new int[max];
        a[2]=1;
        a[3]=1;
        for(int i=4;i<max;i++){
            int x=i;
            int c=0;
            while(x!=1){
                int s= spf[x];
                   while(x!=1 && spf[x]==s)
                   x=x/spf[x];
                   c++;
            }
            a[i]=c;
        }
        
        Deque<Pair> dq= new ArrayDeque<>();
        
        long ans=0l;
        int i=0;
        int j=0;
        while(j<A.length){
            if(dq.isEmpty()) dq.add(new Pair(A[j],a[A[j]]));
            else{
                 while(!dq.isEmpty() && dq.peekLast().cnt<a[A[j]])
                  dq.removeLast();
                  
                  dq.add(new Pair(A[j],a[A[j]]));
            }
            if(j-i+1<B){
                j++;
            }else if(j-i+1==B){
                ans+=(int)dq.peekFirst().ele ;
                ans=ans%m;
                if(dq.peekFirst().cnt ==a[A[i]]) dq.removeFirst();
                i++;
                j++;
            }
        }
        
        return (int)ans;        
    }
}

