// Question Link: https://leetcode.com/problems/complex-number-multiplication/

/*
537. Complex Number Multiplication

A complex number can be represented as a string on the form "real+imaginaryi" where:

real is the real part and is an integer in the range [-100, 100].
imaginary is the imaginary part and is an integer in the range [-100, 100].
i2 == -1.
Given two complex numbers num1 and num2 as strings, return a string of the complex number that represents their multiplications.

Example 1:
Input: num1 = "1+1i", num2 = "1+1i"
Output: "0+2i"
Explanation: (1 + i) * (1 + i) = 1 + i2 + 2 * i = 2i, and you need convert it to the form of 0+2i.
Example 2:
Input: num1 = "1+-1i", num2 = "1+-1i"
Output: "0+-2i"
Explanation: (1 - i) * (1 - i) = 1 + i2 - 2 * i = -2i, and you need convert it to the form of 0+-2i.
 
Constraints:
num1 and num2 are valid complex numbers.
*/



class Solution {
public:
//WAY AND APPROACH
 //THIS RETURN TYPE OF THE FUNCTION MAKES THE CODE EASIEST
 //here,SING NOTATION::(+)==>+ and (+-)==>-
pair<int, int> individual_num(string num) {
    // Find the position of the '+' character(because before + there is real part and after + there is imag(with sing if have (+-==>-))part)
    int i = num.find('+');//IMPORTANT

    // Extract the real and imaginary parts from the string
    //num.substr(i, j) extracts a substring from the string num starting from the index i and having a length of j
    int real = stoi(num.substr(0, i));  // Convert substring before '+' to integer(i==> represents the length of real no)
    int imaginary = stoi(num.substr(i + 1, num.size() - i - 2));  // Convert substring after '+' to integer(num.size() - i - 2==>represents the length of img no)

    // Create a pair representing the complex number
    pair<int, int> indiv_pair(real, imaginary);

    return indiv_pair;
}

// Function to multiply two complex numbers represented as strings
string complexNumberMultiply(string num1, string num2) {
    pair<int, int> a = individual_num(num1);
    pair<int, int> b =  individual_num(num2);

    // Extract real and imaginary parts of both complex numbers
    int real_a = a.first, imag_a = a.second;
    int real_b = b.first, imag_b = b.second;

    // Calculate the real and imaginary parts of the product
    int real_final = real_a * real_b - imag_a * imag_b;
    int imag_final = real_a * imag_b + imag_a * real_b;

    // Format the result as a string 
    string final_complex= to_string(real_final) + '+' + to_string(imag_final) + 'i';
    return final_complex;
}
};
