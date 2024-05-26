// Question Link: https://leetcode.com/problems/split-with-minimum-sum/description/

/*
2578. Split With Minimum Sum

Given a positive integer num, split it into two non-negative integers num1 and num2 such that:
The concatenation of num1 and num2 is a permutation of num.
In other words, the sum of the number of occurrences of each digit in num1 and num2 is equal to the number of occurrences of that digit in num.
num1 and num2 can contain leading zeros.
Return the minimum possible sum of num1 and num2.

Notes:
It is guaranteed that num does not contain any leading zeros.
The order of occurrence of the digits in num1 and num2 may differ from the order of occurrence of num.
 
Example 1:
Input: num = 4325
Output: 59
Explanation: We can split 4325 so that num1 is 24 and num2 is 35, giving a sum of 59. We can prove that 59 is indeed the minimal possible sum.
Example 2:
Input: num = 687
Output: 75
Explanation: We can split 687 so that num1 is 68 and num2 is 7, which would give an optimal sum of 75.

Constraints:
10 <= num <= 10^9
*/



class Solution {
public:
    int splitNum(int num) {
        int x=0,y = 0,k=0,i;
        vector<int> v(10,0);
        while(num){
            x = num%10;
            v[x]++;
            num /= 10;
        }
        x = 0, y = 0;
        for(i = 0; i < 10; i++){
            while(v[i]--){
                if(k&1){
                    x = x*10+i;
                }else{
                    y = y*10+i;
                }
                k ^= 1;
            }
        }
        return x+y;
    }
};
