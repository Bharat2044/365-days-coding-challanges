// Question Link: https://www.interviewbit.com/problems/maximum-substring/

/*
Maximum Substring:

Bookmark
Asked In:
Problem Description:
Given a string A consisting of only characters 'a' and 'b'.
Divide the string into substrings of length B.
Find the subtring with maximum count of 'a' and return the count.
Note: If the length of the string is not a multiple of B and there are some characters left in the end consider them also as a substring.

Problem Constraints:
1 <= |A| <= 105
Ai = {'a', 'b'}
1 <= B <= 105

Input Format:
First argument A is a string.
Second argument is an integer B.

Output Format:
Return an integer.

Example Input:
Input 1:
A = "baab"
B = 2
Input 2:
A = "bba"
B = 2

Example Output:
Output 1:
1
Output 2:
1

Example Explanation:
Explanation 1:
The subtrings are "ba" and "ab".
Both have count of 'a' equal to 1.
Explanation 2:
The substrings are "bb" and "a".
"a" has the highest count which is 1.
*/


int Solution::solve(string A, int B) {
    int ans = INT_MIN;
    
    for(int i=0; i<A.size(); i+=B){
        string str = A.substr(i, B);
        int temp=0;
        
        for(auto it: str){
            if(it=='a')
                temp++;
        }
        
        ans= max(ans,temp);
    }
    
    return ans;
}

