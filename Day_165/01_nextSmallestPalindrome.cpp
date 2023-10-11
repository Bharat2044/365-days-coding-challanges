// Question Link: https://www.interviewbit.com/problems/next-smallest-palindrome/

/*
Next Smallest Palindrome!

Problem Description:
Given a numeric string A representing a large number you need to find the next smallest palindrome greater than this number.

Problem Constraints:
1 <= |A| <= 100
A doesn't start with zeroes and always contain digits from 0-9.

Input Format:
First and only argument is an string A.

Output Format:
Return a numeric string denoting the next smallest palindrome greater than A.

Example Input:
Input 1:
 A = "23545"
Input 2:
 A = "999"

Example Output:
Output 1:
 "23632"
Output 2:
 "1001"
*/



string Solution::solve(string A) {  
   int n = A.size();
   int mid = (n-1)/2;
   string ans = A;
   
   // first make the right half same as left half
   for(int i=0;i<=mid;i++) ans[n-i-1] = ans[i];
   
   // check if at any point whether the value id reduces or not? if yes break; Otherwise return the aans
   // as it is incresed. So, it must have become larger than the A.
   for(int i=0;i<n;i++){
       if(ans[i]<A[i]) break;
       if(ans[i]>A[i]){
           return ans;
       }
   }
   
   // If return is not executed,
   // then try to increase the value starting from mid till value at any point is increased;
   for(int i=mid;i>=0;i--){
       if(ans[i]<'9'){
           ans[i]++; ans[n-i-1] = ans[i];
           return ans;
       }
       else if(ans[i]=='9') 
            ans[i]='0', ans[n-i-1]='0';
   }
   
   // if not returned, then all the digit must be 9. handle it in the last
   string temp = "1";
   
   for(int i=0;i<n-1;i++) 
        temp+="0";
   temp+="1";
   
   return temp;
}

