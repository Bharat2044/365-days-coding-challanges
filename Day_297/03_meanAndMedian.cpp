// Question Link: https://www.codechef.com/problems/MEANMEDIAN


#include <iostream>
using namespace std;

int main()
{
    // your code goes here
    int t;
    cin >> t;
    
    while (t--)
    {
        int x, y;
        cin >> x >> y;
        
        if (3 * x - 2 * y + 1 > y) // EDGE CASE
            cout << y - 1 << " " << y << " " << 3 * x - 2 * y + 1 << endl;
        else
            cout << y + 1 << " " << y << " " << 3 * x - 2 * y - 1 << endl;
    }
    
    return 0;
}
