// Question Link: https://www.codechef.com/problems/HS08TEST?tab=statement

/*
Problem:

Pooja would like to withdraw X $US from an ATM. The cash machine will only accept the transaction if X is a multiple of 5, and Pooja's account balance has enough cash to perform the withdrawal transaction (including bank charges). For each successful withdrawal the bank charges 0.50 $US.

Calculate Pooja's account balance after an attempted transaction.

Input Format:
Each input contains 2 integers X and Y.
X is the amount of cash which Pooja wishes to withdraw.
Y is Pooja's initial account balance.

Output Format:
Output the account balance after the attempted transaction, given as a number with two digits of precision. If there is not enough money in the account to complete the transaction, output the current bank balance.

Constraints:
1. 0 < X ≤ 2000 - the amount of cash which Pooja wishes to withdraw.
2. 0 ≤ Y ≤ 2000 with two digits of precision - Pooja's initial account balance.

Sample 1:
Input                    Output
30  120.00               89.50
Explanation:
Example - Successful Transaction

42  120.00               120.00
Explanation:
Example - Incorrect Withdrawal Amount (not multiple of 5)

300 120.00               120.00
Explanation:
Example - Insufficient Funds
*/



// Time Complexity = O(1), Space COmplexity = O(1)
#include <bits/stdc++.h>
using namespace std;

int main() {
    int x;
    float y;
    cin >> x >> y;
    
    if((x%5 == 0) && (y-x-0.5 >= 0))
        cout << (y-x-0.50) << "\n";
    else
        cout << fixed << y << "\n";
    
    return 0;
}
