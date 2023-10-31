// Question Link: https://www.interviewbit.com/problems/add-binary-strings/

/*
Add Binary Strings

Problem Description:
Given two binary strings A and B. Return their sum (also a binary string).

Problem Constraints:
1 <= length of A <= 105
1 <= length of B <= 105
A and B are binary strings

Input Format:
The two argument A and B are binary strings.

Output Format:
Return a binary string denoting the sum of A and B

Example Input:
Input 1:
A = "100"
B = "11"
Input 2:
A = "110"
B = "10"

Example Output:
Output 1:
"111"
Output 2:
"1000"

Example Explanation:
For Input 1:
The sum of 100 and 11 is 111.
For Input 2: 
The sum of 110 and 10 is 1000.
*/



string Solution::addBinary(string A, string B) {
    int n=A.length(),m=B.length();
    int carry=0;
    string ans="";
    int i=n-1,j=m-1;
    
    while(i>=0 || j>=0 || carry!=0){
        int sum=0;
        if(i>=0){
            sum+=(A[i]-'0');
            i--;
        }
        
        if(j>=0){
            sum+=(B[j]-'0');
            j--;
        }
        
        sum+=carry;
        ans=to_string(sum%2)+ans;
        carry=sum/2;
    }
    
    return ans;
}
