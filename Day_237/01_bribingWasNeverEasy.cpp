// Question Link: https://www.interviewbit.com/problems/bribing-was-never-easy/

/*
Bribing was never Easy!

Problem Description:
There are N students labelled from 1 to N  standing in a queue (initial state of the queue is 1, 2, 3 .... N).
Also each student has certain number of coins with themselves which they can use to bribe the students standing in front of them to exchange position.
For example: if N = 6 and student 5 bribes student 4 then the queue will look like this: 1, 2, 3, 5, 4, 6.

You are given an array A of size N which denotes the current state of the queue, you need to find the minimum number of bribes that took place to get the queue into its current state or is it impossible to reach.
NOTE:
If any student contains x coins then he/she can bribe atmost x students in front of them.
Bribing any student cost 1 coin.
In a single bribing event student standing at index i can only bribe student standing at index i - 1 and then the new index of the student who bribed will be i - 1, he can continue the same steps in the future bribing events.

Problem Constraints:
1 <= N <= 105
1 <= A[i] <= N
0 <= coins with each student <= 100

Input Format:
First argument is an integer array A of size N denoting the current state of queue.
Second argument is an integer array B of size N denoting the coins associated with each student.

NOTE:
Array B is given to you as 0-indexed but B[0] represents coins associates with student labelled 1 similarly for each i in [0, N-1] B[i] represents coins associated with student labelled (i + 1).

Output Format:
Return the minimum number of bribes which took place to get to the current state of queue from the initial state, else if it is not possible to reach the current state then return -1.

Example Input:
Input 1:
 A = [2, 1, 5, 3, 4]
 B = [2, 2, 2, 2, 2]
Input 2:
 A = [2, 5, 1, 3, 4]
 B = [1, 2, 3, 2, 1]

Example Output:
Output 1:
 3
Output 2:
 -1

Example Explanation:
Explanation 1:
 The initial state =>                                                 1 2 3 4 5
 After student 5 moves one position ahead by bribing student 4 =>     1 2 3 5 4
 Now student 5 moves another position ahead by bribing student 3 =>   1 2 5 3 4
 And student 2 moves one position ahead by bribing student 1 =>       2 1 5 3 4
 So the final state is 2,1,5,3,4 after three bribing operations.
Explanation 2:
 Student 5 can't bribe this many people as it contains only 1 coin.
*/


int Solution::solve(vector<int> &A, vector<int> &B) {
    int n=A.size();
    int a[n+1],index[n+1];
    for(int i=1;i<=n;i++){
        a[i]=A[i-1];
        index[a[i]]=i;
    }
    int ans=0;
    for(int i=n;i>=1;i--){
        if(index[i]==i) continue;
        int gap=i-index[i];
        if(gap<0 or gap>B[i-1]) return -1;
        ans+=gap;
        for(int j=index[i];j<i;j++){
            swap(a[j],a[j+1]);
            swap(index[a[j]],index[a[j+1]]);
        }
    }
    return ans;
}
