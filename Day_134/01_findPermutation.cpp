// Question Link: https://www.interviewbit.com/problems/find-permutation/

/*
Find Permutation

Given a positive integer n and a string s consisting only of letters D or I, you have to find any permutation of first n positive integer that satisfy the given input string.

D means the next number is smaller, while I means the next number is greater.

Notes:
Length of given string s will always equal to n - 1
Your solution should run in linear time and space.
Example :

Input 1:
n = 3
s = ID

Return: [1, 3, 2]
*/




vector<int> Solution::findPerm(const string A, int n) {
    int x = 1, y = n;
    vector<int> temp;
    
    for(int i=n-2;i>=0;i--){
        if(A[i]=='I'){
            temp.push_back(y);
            y--;
        }
        else {
            temp.push_back(x);
            x++;
        }
    }
    
    temp.push_back(x);
    reverse(temp.begin(),temp.end());
    
    return temp;
}
