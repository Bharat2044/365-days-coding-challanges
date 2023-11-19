// Question Link: https://www.interviewbit.com/problems/roman-to-integer/

/*
Roman To Integer

Given a string A representing a roman numeral.
Convert A into integer.

A is guaranteed to be within the range from 1 to 3999.

NOTE: Read more 
details about roman numerals at Roman Numeric System

Input Format:
The only argument given is string A.

Output Format:
Return an integer which is the integer verison of roman numeral string.

For Example:
Input 1:
    A = "XIV"
Output 1:
    14
Input 2:
    A = "XX"
Output 2:
    20
*/



int intValue(char r)
{
    if (r=='I'){
        return 1;
    }
    else if (r=='V'){
        return 5;
    }
    else if (r=='X'){
        return 10;
    }
    else if (r=='L'){
        return 50;
    }
    else if (r=='C'){
        return 100;
    }
    else if (r=='D'){
        return 500;
    }
    else{
        return 1000;
    }
}

int Solution::romanToInt(string A) 
{
    int end=A.length()-1;
    int result=intValue(A[end--]);
    
    for(end; end>=0; end--)
    {
        int next=intValue(A[end+1]);
        int curr=intValue(A[end]);
        
        if (curr >= next )
        {
            result += curr;
        }
        else{
            result -= curr;
        }
    }
    
    return result;
}
