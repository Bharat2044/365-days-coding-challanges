// Question Link: https://www.interviewbit.com/problems/n3-repeat-number/

/*
N/3 Repeat Number

Problem Description:
You're given a read-only array of N integers. Find out if any integer occurs more than N/3 times in the array in linear time and constant additional space.
If so, return the integer. If not, return -1.

If there are multiple solutions, return any one.

Problem Constraints:
1 <= N <= 7*105
1 <= A[i] <= 109

Input Format:
The only argument is an integer array A.

Output Format:
Return an integer.

Example Input:
[1 2 3 1 1]

Example Output:
1

Example Explanation:
1 occurs 3 times which is more than 5/3 times.
*/



int Solution::repeatedNumber(const vector<int> &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    int limit=A.size()/3;
    
    if(A.size()==0) 
        return -1;
    if(A.size()==1) 
        return  A[0];
    
    vector<int>v;
    copy(A.begin(),A.end(),back_inserter(v));
    sort(v.begin(),v.end());
    
    for(int i=0;i<A.size()-limit;i++){
        if(v[i]==v[i+limit]) 
            return v[i];
    }    
    
    return -1;
}



