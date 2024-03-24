// Question Link: https://www.codechef.com/problems/RECNDNOS


#include <bits/stdc++.h>
using namespace std;

int main() {
    // your code goes here
    int t;
    cin >> t;
    
    while (t--) {
        int n;
        cin >> n;
        
        int arr[n];
        int m = INT_MIN; 
        
        //to find max element
        for (int i = 0; i < n; i++) {
            cin >> arr[i];

            if (arr[i] > m)
                m = arr[i];
        }
        
        //main code
        int hash[m] = { 0 };
        
        //hashmap with max element
        int count = 1;
        
        for (int i = 0; i < n - 1; i++) {
            if (arr[i] == arr[i + 1])
                count++;
            else {
                if (count == 1)
                    hash[arr[i] - 1] += count;
                else {
                    if (count % 2 == 0)
                        hash[arr[i] - 1] += (count / 2);
                    else
                        hash[arr[i] - 1] += (count / 2) + 1;
                }
                count = 1;
            }

        }

        //for last index
        if (arr[n - 1] != arr[n - 2])
            hash[arr[n - 1] - 1]++;
        else {
            int j = n - 1;
            int c = 0;
            
            while (arr[j] == arr[n - 1]) {
                c++;
                j--;
            }

            if (c % 2 == 0)
                hash[arr[n - 1] - 1] += c / 2;
            else
                hash[arr[n - 1] - 1] += (c / 2) + 1;
        }
        
        //traversing the hash and printing the index of the first maxvalue
        int ans = INT_MIN;
        
        for (int i = 0; i < m; i++) {
            if (hash[i] == 0)
                continue;
            else {
                if (hash[i] > ans)
                    ans = hash[i];
            }
        }
        
        //finding the first occcurrence of maxvalue
        int k = 0;
        
        while (hash[k] != ans) {
            k++;
        }
        
        cout << k + 1 << endl;
    }
    
    return 0;
}
