// Question Link: https://www.interviewbit.com/problems/atoi/

/*
Atoi

There are certain questions where the interviewer would intentionally frame the question vague.

The expectation is that you will ask the correct set of clarifications or state your assumptions before you jump into coding.

Implement atoi to convert a string to an integer.

Example :

Input : "9 2704"
Output : 9
Note: There might be multiple corner cases here. Clarify all your doubts using “See Expected Output”.

Questions:

Q1. Does string contain whitespace characters before the number?

A. Yes

Q2. Can the string have garbage characters after the number?

A. Yes. Ignore it.

Q3. If no numeric character is found before encountering garbage characters, what should I do?

A. Return 0.

Q4. What if the integer overflows?

A. Return INT_MAX if the number is positive, INT_MIN otherwise.

Warning : DO NOT USE LIBRARY FUNCTION FOR ATOI.
*/



int Solution::atoi(const string s) {
    int n=s.size();
       
    string temp="";
    int i=0;
    
    while(i<n && s[i]==' ')
    {
        i++;
    }
    
    if(s[i]=='-' || s[i]=='+')
    {
        temp+=s[i];
        i++;
    }
    
    while(i<n && s[i]=='0')
    {
        i++;
    }
    
    while(i<n && s[i]>='0' && s[i]<='9')
    {
        temp+=s[i];
        i++;
    }
    
    bool neg=false;
    
    if(temp.empty() || temp=="+" || temp=="-")
    {
        return 0;
    }
    
    if( !temp.empty() && temp[0]=='-')
    {
        neg=true;           
    }
    
    if(neg && temp.size()>=13)
    {
        return INT_MIN;
    }
    
    if(!neg && temp.size()>=13)
    {
        return INT_MAX;
    }
    
    long long val=stoll(temp);
    
    if(val>INT_MAX)
    {
        return INT_MAX;
    }
    
    if(val<INT_MIN)
    {
        return INT_MIN;
    }
    
    return val;       
}
