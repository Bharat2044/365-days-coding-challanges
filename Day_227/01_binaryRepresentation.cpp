// Question Link: https://www.interviewbit.com/problems/binary-representation/

/*
Binary Representation

Given a number N >= 0, find its representation in binary.

Example:
if N = 6,
binary form = 110

Problem Approach:
Complete code in the hint.
*/



string Solution::findDigitsInBinary(int A) {
    string s;
    
    if(A>0){
        for(;A>=1;A=A/2){
            if(A%2==0) 
                s=s+'0';
            else 
                s=s+'1';
        }
    
        for(int i=0;i<s.length()/2;i++){
            swap(s[i],s[s.length()-1-i]);
        }
    }
    else 
        s=s+'0';
    
    return s;
}
