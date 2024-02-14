// Question Link: https://leetcode.com/problems/stone-game-v/

/*
1563. Stone Game V

There are several stones arranged in a row, and each stone has an associated value which is an integer given in the array stoneValue.
In each round of the game, Alice divides the row into two non-empty rows (i.e. left row and right row), then Bob calculates the value of each row which is the sum of the values of all the stones in this row. Bob throws away the row which has the maximum value, and Alice's score increases by the value of the remaining row. If the value of the two rows are equal, Bob lets Alice decide which row will be thrown away. The next round starts with the remaining row.

The game ends when there is only one stone remaining. Alice's is initially zero.
Return the maximum score that Alice can obtain.

Example 1:
Input: stoneValue = [6,2,3,4,5,5]
Output: 18
Explanation: In the first round, Alice divides the row to [6,2,3], [4,5,5]. The left row has the value 11 and the right row has value 14. Bob throws away the right row and Alice's score is now 11.
In the second round Alice divides the row to [6], [2,3]. This time Bob throws away the left row and Alice's score becomes 16 (11 + 5).
The last round Alice has only one choice to divide the row which is [2], [3]. Bob throws away the right row and Alice's score is now 18 (16 + 2). The game ends because only one stone is remaining in the row.
Example 2:
Input: stoneValue = [7,7,7,7,7,7,7]
Output: 28
Example 3:
Input: stoneValue = [4]
Output: 0
 
Constraints:
1 <= stoneValue.length <= 500
1 <= stoneValue[i] <= 106
*/



class Solution {
public:

   int dp[501][501];

    int solve(int start,int end,vector<int>&stoneValue,vector<int>&pref)
    {
          if(end==start) return 0;
          if(end<start)return 0;
        
        if(dp[start][end]!=-1)return dp[start][end];

          int score=0;  
           for(int i=start;i<=end;i++)
           {
               int lf=(start==0)?pref[i]:pref[i]-pref[start-1]; //leftSum
               int rf=pref[end]-pref[i];   //rightSum
  
             
               if(lf>rf)
               {
                   int val=rf+solve(i+1,end,stoneValue,pref);
                   score=max(score,val);
               }
               else if(rf>lf)
               {
                   int val=lf+solve(start,i,stoneValue,pref);
                   score=max(score,val);
               }
               else{
                     int val1=lf+solve(start,i,stoneValue,pref);
                     int val2=rf+solve(i+1,end,stoneValue,pref);
                     int mx=max(val1,val2);
                     score=max(score,mx);
               }
           }

           return dp[start][end]=score;
    }

    int stoneGameV(vector<int>& stoneValue) {
         
         memset(dp,-1,sizeof(dp));

         vector<int>pref(stoneValue.size()+1,0);
         pref[0]=stoneValue[0];

         for(int i=1;i<stoneValue.size();i++)
         {
                pref[i]=pref[i-1]+stoneValue[i];
         }

         return solve(0,(int)stoneValue.size()-1,stoneValue,pref);
    }
};
