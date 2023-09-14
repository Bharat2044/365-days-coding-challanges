// Question Link: https://leetcode.com/problems/valid-perfect-square/

/*
367. Valid Perfect Square

Given a positive integer num, return true if num is a perfect square or false otherwise.

A perfect square is an integer that is the square of an integer. In other words, it is the product of some integer with itself.
You must not use any built-in library function, such as sqrt.

Example 1:
Input: num = 16
Output: true
Explanation: We return true because 4 * 4 = 16 and 4 is an integer.
Example 2:
Input: num = 14
Output: false
Explanation: We return false because 3.742 * 3.742 = 14 and 3.742 is not an integer.
 
Constraints:
1 <= num <= 231 - 1
*/



class Solution {
public:
    double ronakSqrt(int n)
    {
        if(n<2)
            return double(n);
        
        // store the half of the given number e.g from 256 => 128
        double sqrt = n / 2;
        double temp = 0;

        // Iterate until sqrt is different of temp, that is updated on the loop
        while(sqrt != temp){
            temp = sqrt;
            sqrt = ( n/temp + temp) / 2;
        }

        return sqrt;
    }

    bool isPerfectSquare(int num) 
    {
        double a=ronakSqrt(num);
        double b=ceil(ronakSqrt(num));
        cout<<a<<endl<<b<<endl;
        if(a == b)
            return true;
        return false;
    }
};
