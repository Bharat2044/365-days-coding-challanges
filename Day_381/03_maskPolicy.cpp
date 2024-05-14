// Question Link: https://www.codechef.com/problems/MASKPOL


#include <iostream>
using namespace std;

int main() {
    // your code goes here
    int tests;
    cin >> tests;
    
    while (tests--) {
        int population;
        cin >> population;
    
        int infected;
        cin >> infected;
    
        int uninfected = population - infected;
    
        if (infected <= uninfected)
            cout << infected << endl;
        else
            cout << uninfected << endl;
    }
    
    return 0;
}
