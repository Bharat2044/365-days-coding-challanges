// Question Link: https://www.codechef.com/problems/STFOOD


#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); 
    cin.tie(0);
    
	int T;
	cin >> T;
	
	while (T--){
	    int N,S,P,V,Profit, MaxProfit=0;
	    cin >> N;
	    
	    while (N--){
	        cin >> S >>P >>V;
	        
	        Profit = (P/(S+1)) * V;
	        MaxProfit = max(MaxProfit,Profit);
	    }
	    
	    cout << MaxProfit <<"\n";
	}
	
	return 0;
}
