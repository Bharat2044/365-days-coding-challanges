// Question Link: https://leetcode.com/problems/rotated-digits/

/*
788. Rotated Digits

An integer x is a good if after rotating each digit individually by 180 degrees, we get a valid number that is different from x. Each digit must be rotated - we cannot choose to leave it alone.

A number is valid if each digit remains a digit after rotation. For example:

0, 1, and 8 rotate to themselves,
2 and 5 rotate to each other (in this case they are rotated in a different direction, in other words, 2 or 5 gets mirrored),
6 and 9 rotate to each other, and
the rest of the numbers do not rotate to any other number and become invalid.
Given an integer n, return the number of good integers in the range [1, n].

Example 1:
Input: n = 10
Output: 4
Explanation: There are four good numbers in the range [1, 10] : 2, 5, 6, 9.
Note that 1 and 10 are not good numbers, since they remain unchanged after rotating.
Example 2:
Input: n = 1
Output: 0
Example 3:
Input: n = 2
Output: 1
 
Constraints:
1 <= n <= 104
*/



class Solution 
{
public:
    int rotatedDigits(int n) 
    {
        map<int,int> m;
        m[0]=0; m[1]=1; m[8]=8; m[6]=9; m[9]=6; m[2]=5; m[5]=2;
        int count=0;
        for(int x=1; x<=n; x++)
        {
            string s=to_string(x);
            auto i1=s.find("2"), i2=s.find("5"), i3=s.find("6"), i4=s.find("9"), i5=s.find("3"), i6=s.find("4"), i7=s.find("7");
            if((i1!=string::npos || i2!=string::npos || i3!=string::npos || i4!=string::npos) && (i5==string::npos && i6==string::npos && i7==string::npos)) count++;
        }
        return count;
    }
};
