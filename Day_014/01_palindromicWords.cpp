// Question Link: https://www.interviewbit.com/problems/palindromic-words/

/*
Palindromic Words:

Problem Description:
Given a sentence as a string A.
Return the number of palindromic words in the sentence.

Problem Constraints:
1 <= A <= 105
Ai = {Lowercase English letters and whitespaces}

Input Format:
The first and only argument is a string A.

Output Format:
Return an integer.

Example Input:
Input 1:
A = "the fastest racecar"
Input 2:
A = "wow mom"

Example Output:
Output 1:
1
Output 2:
2

Example Explanation:
Explanation 1:
The word "racecar" is only a palindromic word in the sentence "the fastest racecar".
Explanation 2:
The words "wow" and "mom" both are palindromic word in the sentence "wow mom".
*/



bool ispalidrome(string A){   
    int i = 0, j = A.length()-1;
   
    while(i < j) {
        if(A[i] != A[j]) 
            return false;
        i++;
        j--;
    }
    
    return true;
}

int Solution::solve(string A) {   
    int count = 0;
    
    for(int i=0; i<A.length(); i++) {
        string temp = "";
        
        while((A[i] != ' ') && (i < A.length())) {
            temp += A[i];
            i++;
        }
        
        if(ispalidrome(temp) == true) 
            count++;
    }
    
    return count;   
}
