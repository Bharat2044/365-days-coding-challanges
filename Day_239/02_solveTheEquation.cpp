// Question Link: https://leetcode.com/problems/solve-the-equation/

/*
640. Solve the Equation

Solve a given equation and return the value of 'x' in the form of a string "x=#value". The equation contains only '+', '-' operation, the variable 'x' and its coefficient. 
You should return "No solution" if there is no solution for the equation, or "Infinite solutions" if there are infinite solutions for the equation.

If there is exactly one solution for the equation, we ensure that the value of 'x' is an integer.

Example 1:
Input: equation = "x+5-3+x=6+x-2"
Output: "x=2"
Example 2:
Input: equation = "x=x"
Output: "Infinite solutions"
Example 3:
Input: equation = "2x=x"
Output: "x=0"
 
Constraints:
3 <= equation.length <= 1000
equation has exactly one '='.
equation consists of integers with an absolute value in the range [0, 100] without any leading zeros, and the variable 'x'.
*/



class Solution {
 public:
  string solveEquation(string equation) {
    const string lhsEquation = equation.substr(0, equation.find('='));
    const string rhsEquation = equation.substr(equation.find('=') + 1);
    const auto& [lhsCoefficient, lhsConstant] = calculate(lhsEquation);
    const auto& [rhsCoefficient, rhsConstant] = calculate(rhsEquation);
    const int coefficient = lhsCoefficient - rhsCoefficient;
    const int constant = rhsConstant - lhsConstant;

    if (coefficient == 0 && constant == 0)
      return "Infinite solutions";
    if (coefficient == 0 && constant != 0)
      return "No solution";
    return "x=" + to_string(constant / coefficient);
  }
 private:
  pair<int, int> calculate(const string& s) {
    int coefficient = 0;
    int constant = 0;
    int num = 0;
    int sign = 1;

    for (int i = 0; i < s.length(); ++i) {
      const char c = s[i];
      if (isdigit(c))
        num = num * 10 + (c - '0');
      else if (c == '+' || c == '-') {
        constant += sign * num;
        sign = c == '+' ? 1 : -1;
        num = 0;
      } else {
        if (i > 0 && num == 0 && s[i - 1] == '0')
          continue;
        coefficient += num == 0 ? sign : sign * num;
        num = 0;
      }
    }
    return {coefficient, constant + sign * num};
  }
};
