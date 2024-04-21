// Question Link: https://www.interviewbit.com/problems/triplets-with-sum-between-given-range/

/*
Triplets with Sum between given range

Problem Description:
Given an array of real numbers greater than zero in form of strings. Find if there exists a triplet (a,b,c) such that 1 < a+b+c < 2. Return 1 for true or 0 for false.
O(n) solution is expected.
Note: You can assume the numbers in strings don't overflow the primitive data type and there are no leading zeroes in numbers. Extra memory usage is allowed.

Problem Constraints:
1 <= |A| <= 10^6

Input Format:
The first argument is an array of strings A.

Output Format:
Return an integer, 1 for true or 0 for false.

Example Input:
A = ["0.6", "0.7", "0.8", "1.2", "0.4"]

Example Output:
1

Example Explanation:
Given [0.6, 0.7, 0.8, 1.2, 0.4],
You should return 1
as
0.6+0.7+0.4=1.7
1<1.7<2
Hence, the output is 1.
*/




vector<double> get(vector<double> A) {
    double min1 = 10, min2 = 10, min3 = 10, max1 = -1, max2 = -1, max3 = -1;
    
    for(int i=0; i<A.size(); i++) {
        if(A[i]<min1) {
            min3 = min2;
            min2 = min1;
            min1 = A[i];
        }
        else if(A[i]<min2) {
            min3 = min2;
            min2 = A[i];
        }
        else if(A[i]<min3) {
            min3 = A[i];
        }
        
        if(A[i]>max1) {
            max3 = max2;
            max2 = max1;
            max1 = A[i];
        }
        else if(A[i]>max2) {
            max3 = max2;
            max2 = A[i];
        }
        else if(A[i]>max3) {
            max3 = A[i];
        }
    }
    
    vector<double> max_min{min1, min2, min3, max1, max2, max3};
    return max_min;
}

int Solution::solve(vector<string> &arr) {
    vector<double> A, B, C;
    int n = arr.size();
    
    for(int i=0; i< n; i++) {
        if(stod(arr[i]) < (double)2/3)
            A.push_back(stod(arr[i]));
        else if ( stod(arr[i]) < 1)
            B.push_back(stod(arr[i]));
        else
            C.push_back(stod(arr[i]));
    }
    
    vector<double> A_maxmins = get(A), B_maxmins = get(B), C_maxmins = get(C);

    if((A_maxmins[3] + A_maxmins[4] + A_maxmins[5] > 1) || ((A_maxmins[3] + A_maxmins[4] + B_maxmins[3] > 1) &&
    (A_maxmins[3] + A_maxmins[4] + B_maxmins[3] < 2)) || (A_maxmins[0] + A_maxmins[1] + C_maxmins[0] <2) ||
    (A_maxmins[0] + B_maxmins[0] + B_maxmins[1] < 2) || (A_maxmins[0] + B_maxmins[0] + C_maxmins[0] < 2) )
        return 1;
        
    return 0;
}
