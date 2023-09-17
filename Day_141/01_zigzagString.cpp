// Question Link: https://www.interviewbit.com/problems/zigzag-string/

/*
Zigzag String

The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this: (you may want to display this pattern in a fixed font for better legibility)

P.......A........H.......N
..A..P....L....S....I...I....G
....Y.........I........R
And then read line by line: PAHNAPLSIIGYIR

Write the code that will take a string and make this conversion given a number of rows:

string convert(string text, int nRows);
convert("PAYPALISHIRING", 3) should return "PAHNAPLSIIGYIR"
**Example 2 : **
ABCD, 2 can be written as
A....C
...B....D
and hence the answer would be ACBD.
*/



string Solution::convert(string s, int n) {
    if (n == 1 || s.length() <= n) {
        return s;
    }

    vector<string> str(n, "");
   
    int i = 0;
    while(i < s.size()) {
        int j = 0;
        while(j < n && i < s.size()) {
            str[j] += s[i++];
            j++;
        }
       
        j -= 2;
        while(j > 0 && i < s.size()) {
            str[j] += s[i++];
            j--;
        }
    }
     
    string res = "";
    for(int i = 0; i < n; i++) {
        res += str[i];
    }
    return res;
}
