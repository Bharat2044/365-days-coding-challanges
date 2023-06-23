// Question Link: https://www.codechef.com/problems/INTEST

/*
Problem:

You are given N integers. Find the count of numbers divisible by K.

Input Format:
The input begins with two positive integers N, K. The next N lines contains one positive integer each denoted by Ai.

Output Format
Output a single number denoting how many integers are divisible by K.

Constraints:
1 ≤ N, K ≤ 10^7
1 ≤ Ai ≤ 10^9

Sample 1:
Input
Output
7 3
1
51
966369
7
9
999996
11
4
Explanation:
The integers divisible by 3 are 51,966369,9, and 999996. Thus, there are 4 integers in total.
*/



#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    int count = 0;
        
    for (int i=0; i<n; i++)  {
        int a;
        cin >> a;
        
        if (a%k == 0)
            count++;
    }

    cout << count << endl;
    
    return 0;
}
