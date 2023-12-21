// Question Link: https://www.interviewbit.com/problems/points-on-the-straight-line/

/*
Points on the Straight Line

Problem Description:
Given N points on a 2D plane, find the maximum number of points that lie on the same straight line.
You will be given 2 arrays A and B. Each point is represented by (A[i], B[i])

Problem Constraints:
1 <= |A| <= 500
|A| == |B|
-109 <= Ai, Bi <= 109

Input Format:
The first argument is an integer array A.
The second argument is an integer array B.

Output Format:
Return an integer.

Example Input:
A = [1, 2]
B = [1, 2]

Example Output:
2

Example Explanation:
The points on the 2D plane are (1, 1) and (2, 2). A line with the slope (m = 1) passes through both the points.
*/



int Solution::maxPoints(vector<int> &A, vector<int> &B) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    
    int res=0;
    
    for(int i=0;i<A.size();i++)
    {  
        unordered_map<double,int>mp;
        double x1=(double)A[i],y1=(double)B[i];
        int same=0;
        
        for(int j=i+1;j<B.size();j++)
        {
             double x2=(double)A[j],y2=(double)B[j];
             if(x1==x2 && y1==y2) //for same points
             {
                 same++;
             }
             else if(x2==x1)
             {
                 mp[INT_MAX]++;
             }
            else{
                double slope=(y2-y1)/(x2-x1);
                mp[slope]++;
            }
        }
        
        int temp=0;
        
        for(auto x:mp)
        {  
            // cout<<i<<" "<<x.first<<" "<<x.second<<endl;
            temp=max(temp,x.second);
        }
        
        temp++;
        temp=temp+same;
        res=max(res,temp);
    }
    
    return res;
}
