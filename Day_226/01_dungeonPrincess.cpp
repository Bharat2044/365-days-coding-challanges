// Question Link: https://www.interviewbit.com/problems/dungeon-princess/

/*
Dungeon Princess

The demons had captured the princess (P) and imprisoned her in the bottom-right corner of a dungeon. The dungeon consists of M x N rooms laid out in a 2D grid. Our valiant knight (K) was initially positioned in the top-left room and must fight his way through the dungeon to rescue the princess.

The knight has an initial health point represented by a positive integer. If at any point his health point drops to 0 or below, he dies immediately.

Some of the rooms are guarded by demons, so the knight loses health (negative integers) upon entering these rooms; other rooms are either empty (0’s) or contain magic orbs that increase the knight’s health (positive integers).
In order to reach the princess as quickly as possible, the knight decides to move only rightward or downward in each step.

Write a function to determine the knight’s minimum initial health so that he is able to rescue the princess.
For example, given the dungeon below, the initial health of the knight must be at least 7 if he follows the optimal path
RIGHT-> RIGHT -> DOWN -> DOWN.

Dungeon Princess: Example 1
Input arguments to function:
Your function will get  an M*N matrix (2-D array) as input which represents the 2D grid as described in the question. Your function should return an integer corresponding to the knight’s minimum initial health required. 

Note:
The knight’s health has no upper bound.
Any room can contain threats or power-ups, even the first room the knight enters and the bottom-right room where the princess is imprisoned.
*/



int Solution::calculateMinimumHP(vector<vector<int>> &a) {

    int n=a.size();
    int m=a[0].size();
    
     int l=1,r=1e9;
     int dp[n][m];

     while(l<=r)
     {
         int mid=(l+r)/2;
         dp[0][0]=mid+a[0][0]; //here mid is the value on which we are checking for the validation

         for(int i=0;i<n;i++)
         {
             for(int j=0;j<m;j++)
             {
                 if(i && !j) if(dp[i-1][j]>0) dp[i][j]=dp[i-1][j]+a[i][j]; else dp[i][j]=-1; // !j => j==0 => first column

                 if(!i && j) if(dp[i][j-1]>0) dp[i][j]=dp[i][j-1]+a[i][j]; else dp[i][j]=-1; // !i => i==0 => first row
                 
                 if(i && j)
                 {
                     if(dp[i-1][j]<=0 && dp[i][j-1]<=0) dp[i][j]=-1;    //if both upward and leftward is less than or equal to zero this means knight has died
                     else dp[i][j]=max(dp[i-1][j],dp[i][j-1])+a[i][j]; //else it will take greedily best path
                 }
             }
         }

         if(dp[n-1][m-1]>0)r=mid-1; //if we can reach the (n-1,m-1) cell by this 'mid' value then we are checking for lesser values of l
         else l=mid+1; //if we cannot reach then we must have to increase the lower limit to (mid+1)
     }

     return l;
}



