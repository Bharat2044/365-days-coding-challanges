// Question Link: https://www.interviewbit.com/problems/convert-the-amount-in-number-to-words/

/*
Convert the amount in number to words

Problem Description:
Our company wants to create a data entry verification system. Given an amount in words and an amount indicated by data entry person in numbers, you have to detect whether the amounts are the same or not.

Note:
There are a lot of corner cases to be considered. The interviewer expects you to take care of them.
Every word needs to be separated using "-" rather than a space character https://en.wikipedia.org/wiki/Indian_numbering_system
"Use Expected Output option" to clear further doubts.

Problem Constraints:
1 <= |A| <= 9
1 <= |B| <= 100

Input Format:
String num: Amount written in digits as a string. This string will be an integer number without having any commas in between the digits.
String words: Amount written in words according to Indian Numbering System.

Output Format:
An integer
1: Values match
0: Otherwise

Example Input:
String num = "1234"
String words = "one-thousand-two-hundred-and-thirty-four"

Example Output:
1
*/



string one[] = { "", "one-", "two-", "three-", "four-",
                 "five-", "six-", "seven-", "eight-",
                 "nine-", "ten-", "eleven-", "twelve-",
                 "thirteen-", "fourteen-", "fifteen-",
                 "sixteen-", "seventeen-", "eighteen-",
                 "nineteen-" };
 
// strings at index 0 and 1 are not used, they are to
// make array indexing simple
string ten[] = { "", "", "twenty-", "thirty-", "forty-",
                 "fifty-", "sixty-", "seventy-", "eighty-",
                 "ninety-" };
 
// n is 1- or 2-digit number
string numToWords(int n, string s)
{
    string str = "";
    // if n is more than 19, divide it
    if (n > 19)
        str += ten[n / 10] + one[n % 10];
    else
        str += one[n];
 
    // if n is non-zero
    if (n)
        str += s;
 
    return str;
}
 
// Function to print a given number in words
string convertToWords(long n)
{
    // stores word representation of given number n
    string out;
 
    // handles digits at ten millions and hundred
    // millions places (if any)
    out += numToWords((n / 10000000), "crore-");
 
    // handles digits at hundred thousands and one
    // millions places (if any)
    out += numToWords(((n / 100000) % 100), "lakh-");
 
    // handles digits at thousands and tens thousands
    // places (if any)
    out += numToWords(((n / 1000) % 100), "thousand-");
 
    // handles digit at hundreds places (if any)
    out += numToWords(((n / 100) % 10), "hundred-");
 
    if (n > 100 && n % 100)
        out += "and-";
 
    // handles digits at ones and tens places (if any)
    out += numToWords((n % 100), "");
   
    //Handling the n=0 case
    if(out=="")
        out = "zero";
    else 
        out.pop_back();    
    
    return out;
}

int Solution::solve(string A, string B) {
    int n=stoi(A);
    
    return B==convertToWords(n);
}

