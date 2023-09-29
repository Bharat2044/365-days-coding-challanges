// Question Link: https://codechef.com/problems/HELPLIRA


#include <iostream>
using namespace std;

int main() {
	// your code goes here
	int n,mini,maxi;
	float area,min,max;
	int x1,x2,x3,y1,y2,y3;
	
	min=1500000;
	max=0;
	cin>>n;
	int i=1;
	
	while(n--){
	    cin>>x1>>y1>>x2>>y2>>x3>>y3;
	    area=(x1*(y2-y3)+x2*(y3-y1)+x3*(y1-y2))/2;
	    
	    if(area<0){
	        area=-1*area;
	    }
	    
	    if(area<=min){
	        min=area;
	        mini=i;
	    }
	    
	    if(area>=max){
	        max=area;
	        maxi=i;
	    }
	    i++;
	}
	cout<<mini<<" "<<maxi;
	
	return 0;
}
