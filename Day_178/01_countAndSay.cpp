// Question Link: https://www.interviewbit.com/problems/count-and-say/

/*
Count And Say

Problem Description:
The count-and-say sequence is the sequence of integers beginning as follows: 
1, 11, 21, 1211, 111221, ...
1 is read off as one 1 or 11. 11 is read off as two 1s or 21.
21 is read off as one 2, then one 1 or 1211.

Given an integer n, generate the nth sequence.

Note: The sequence of integers will be represented as a string.

Example:
if n = 2, the sequence is 11.
 */



string Solution::countAndSay(int A) {
    string s="1";
    while(A-1){
        string a;
        int n=s.size();
        int count=1;
        for(int i=0;i<n;i++){
            if(s[i]==s[i+1]&&i!=n-1){
                count++;
            }
            else{
                a.push_back(count+'0');
                a.push_back(s[i]);
                count=1;
            }
        }
        s.clear();
        s=a;
        a.clear();
        A--;
    }
    return s;
}
