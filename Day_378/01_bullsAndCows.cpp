// Question Link: https://www.interviewbit.com/problems/bulls-and-cows/

/*
Bulls and Cows

Problem Description:
 You are playing the Bulls and Cows game with your friend.

You write down a secret number and ask your friend to guess what the number is. When your friend makes a guess, you provide a hint with the following info:
The number of "bulls", which are digits in the guess that are in the correct position.
The number of "cows", which are digits in the guess that are in your secret number but are located in the wrong position. 
Specifically, the non-bull digits in the guess that could be rearranged such that they become bulls. 
Given the secret number secret and your friend's guess guess, return the hint for your friend's guess.

The hint should be formatted as "xAyB", where x is the number of bulls and y is the number of cows. Note that both secret and guess may contain duplicate digits.

Problem Constraints:
1 <= secret.length, guess.length <= 100000
secret.length == guess.length
secret and guess consist of digits only.

Input Format:
First argument is string denoting secret string 
Second argument is string denoting guess string 

Output Format:
Return the hint for you friend's guess.

Example Input:
Input 1:
secret = "1807", guess = "7810"
Input 2:
secret = "1123", guess = "0111"

Example Output:
Ouput 1:
"1A3B"
Ouput 2:
"1A1B"

Example Explanation:
Explanation 1:
Bulls are connected with a '|':
"1807"
  |
"7810"
Explanation 2:
Bulls are connected with a '|' 
"1123"        "1123"
  |      or     |
"0111"        "0111"
Note that only one of the two unmatched 1s is counted as a cow since 
the non-bull digits can only be rearranged to allow one 1 to be a bull.
*/



string Solution::solve(string A, string B) {
    unordered_map<char,int> mp;
    int n = A.length();
    int b=0,c=0;

    for(int i=0; i<n; i++){
        if(A[i]==B[i]){
            b++;
        }else{
            mp[A[i]]++;
        }
    }
    
    for(int i=0; i<n; i++){
        if(A[i]!=B[i] && mp[B[i]]>0){
            mp[B[i]]--;
            c++;
        }
    }
    
    return to_string(b) + "A" + to_string(c) + "B";
}
