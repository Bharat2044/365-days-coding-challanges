// Question Link: https://www.codechef.com/problems/GCDPERM


#include <iostream>
#include <vector>
using namespace std;

vector<int> subsetGCD(int n , int k){
    for(int gcd = n ; gcd > 0 ; --gcd){
        vector<int> multiples;
        
        for(int i = gcd ; i <= n ; i += gcd){
            multiples.push_back(i);
            if(multiples.size() == k){
                return multiples;
            }
        }
    }
    
    return vector<int>();
}

int main(){
    int t,n,k;
    cin >> t;
    
    while(t--){
        cin >> n >> k;
    
         vector<int> subset = subsetGCD(n,k);
    
         for(int num : subset){
             cout << num << " " ;
         }
        
        cout << endl;
    }
    
    return 0;
}
