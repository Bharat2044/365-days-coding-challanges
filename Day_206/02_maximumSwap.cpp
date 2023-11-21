// Question Link: https://leetcode.com/problems/maximum-swap/

/*
670. Maximum Swap

You are given an integer num. You can swap two digits at most once to get the maximum valued number.

Return the maximum valued number you can get.

Example 1:
Input: num = 2736
Output: 7236
Explanation: Swap the number 2 and the number 7.
Example 2:
Input: num = 9973
Output: 9973
Explanation: No swap.
 
Constraints:
0 <= num <= 108
*/



class Solution {
public:
    int maximumSwap(int num) {
        vector<int>digits;
        while(num>0){
            digits.push_back(num%10);
            num/=10;
        }
        int maxi=0;
        vector<int>temp(digits.size());
        temp[0]=-1;
        for(int i=1;i<digits.size();i++){
            temp[i]=digits[maxi]>digits[i]?maxi:-1;
            if(digits[i]>digits[maxi]){
                maxi=i;
            }
        }

        for(int i=temp.size()-1;i>=0;i--){
            if(temp[i]!=-1){
                swap(digits[i],digits[temp[i]]);
                break;
            }
        }
        int mul=pow(10,temp.size()-1);
        int org=0;
        for(int i=digits.size()-1;i>=0;i--){
            org+=(digits[i]*mul);
            mul/=10;
        }

        return org;        
    }
};
