// Question Link: https://www.interviewbit.com/problems/max-sum-without-adjacent-elements/

/*
Max Sum Without Adjacent Elements

Given a 2 x N grid of integer, A, choose numbers such that the sum of the numbers
is maximum and no two chosen numbers are adjacent horizontally, vertically or diagonally, and return it.
Note: You can choose more than 2 numbers.

Input Format:
The first and the only argument of input contains a 2d matrix, A.

Output Format:
Return an integer, representing the maximum possible sum.

Constraints:
1 <= N <= 20000
1 <= A[i] <= 2000

Example:
Input 1:
    A = [   [1]
            [2]    ]
Output 1:
    2
Explanation 1:
    We will choose 2.
Input 2:
    A = [   [1, 2, 3, 4]
            [2, 3, 4, 5]    ]  
Output 2:
    We will choose 3 and 5.
*/



int Solution::adjacent(vector<vector<int> >&arr) {
    int n=arr[0].size();
    int prev2=0;
    int prev1 = max(arr[0][0],arr[1][0]);
     
    for(int i=1;i<n;i++){       
        int take=max(arr[0][i],arr[1][i]);
        
        if(i-2>=0)
            take+=prev2;
         
        int not_take=0+prev1;   
        int curr=max(take,not_take);
        
        prev2=prev1;
        prev1=curr;       
    }
   
    return prev1;   
}
