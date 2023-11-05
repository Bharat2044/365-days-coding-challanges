// Question Link: https://www.interviewbit.com/problems/stepping-numbers/

/*
Stepping Numbers

Problem Description:
Given A and B you have to find all stepping numbers in the range A to B (both inclusive).

The stepping number:
A number is called as a stepping number if the adjacent digits have a difference of 1.

For e.g. 123 is a stepping number, but 358 is not a stepping number

Problem Constraints:
0 <= A <= 104
1 <= B <= 107
A <= B

Input Format:
First argument is an integer A.
Second argument is an integer B.

Output Format:
Return a integer array sorted in ascending order denoting the stepping numbers between A and B.

Example Input:
Input 1:
 A = 10
 B = 20
 
Example Output:
Output 1:
[10, 12]
 
Example Explanation:
Explanation 1:
 The stepping numbers in range [10, 20] are 10, and 12. 
*/


void helper(int A,int B,vector<int> &ans ,int num,int last)
{
    if(num<=B)
    {
    if(num>=A && num<=B)
    {
        ans.push_back(num);
    }
    if(last<9)
    helper(A,B,ans,num*10+last+1,last+1);
    if(last>0)
    helper(A,B,ans,num*10+last-1,last-1);
   
    }
}

vector<int> Solution::stepnum(int A, int B) {
    vector<int> ans;
    for(int i=0;i<=9;i++)
    {
        if(i==1 )continue;
        helper(A,B,ans,i,i);
    }
    sort(ans.begin(),ans.end());
    return ans;
}
