// Question Link: https://www.interviewbit.com/problems/multiply-strings/

/*
Multiply Strings

Problem Description:
Given two numbers represented as strings, return the multiplication of the numbers as a string.

Note: 
The numbers can be arbitrarily large and are non-negative.
Your answer should not have leading zeroes. For example, 00 is not a valid answer.
DO NOT USE BIG INTEGER LIBRARIES ( WHICH ARE AVAILABLE IN JAVA / PYTHON ). We will retroactively disqualify such submissions and the submissions will incur penalties.

Problem Constraints:
1 <= |A|, |B| <= 104
1 <= |A| * |B| <= 106

Input Format:
The first argument is a string A, representing the first number.
The second argument is a string B, representing the second number.

Output Format:
Return a string, equal to the product of A and B.

Example Input:
A = "10"
B = "12"

Example Output:
"120"

Example Explanation:
A = 10 and B = 12, A * B is 120, return it in the string without leading zeroes.
*/


string Solution::multiply(string num1, string num2) {
     if (num1 == "0" || num2 == "0") return "0";
       
        // num1.size() + num2.size() == max no. of digits
        vector<int> num(num1.size() + num2.size(), 0);
       
        // build the number by multiplying one digit at the time
        for (int i = num1.size() - 1; i >= 0; --i) {
            for (int j = num2.size() - 1; j >= 0; --j) {
                num[i + j + 1] += (num1[i] - '0') * (num2[j] - '0');
                num[i + j] += num[i + j + 1] / 10;
                num[i + j + 1] %= 10;
            }
        }
       
        // skip leading 0's
        int i = 0;
        while (i < num.size() && num[i] == 0) ++i;
       
        // transofrm the vector to a string
        string res = "";
        while (i < num.size()) res.push_back(num[i++] + '0');
       
        return res;
}
