// Question Link: https://www.interviewbit.com/problems/sliding-window-maximum/

/*
Sliding Window Maximum

Given an array of integers A.  There is a sliding window of size B which 

is moving from the very left of the array to the very right. 

You can only see the w numbers in the window. Each time the sliding window moves 

rightwards by one position. You have to find the maximum for each window. 

The following example will give you more clarity.

The array A is [1 3 -1 -3 5 3 6 7], and B is 3.

Window position	Max
———————————-	————————-
[1  3  -1] -3  5  3  6  7	3
1 [3  -1  -3] 5  3  6  7	3
1  3 [-1  -3  5] 3  6  7	5
1  3  -1 [-3  5  3] 6  7	5
1  3  -1  -3 [5  3  6] 7	6
1  3  -1  -3  5 [3  6  7]	7
Return an array C, where C[i] is the maximum value of from A[i] to A[i+B-1].

Note: If B > length of the array, return 1 element with the max of the array.

Input Format:
The first argument given is the integer array A.
The second argument given is the integer B.

Output Format:
Return an array C, where C[i] is the maximum value of from A[i] to A[i+B-1]

For Example:
Input 1:
    A = [1, 3, -1, -3, 5, 3, 6, 7]
    B = 3
Output 1:
    C = [3, 3, 5, 5, 6, 7]
*/




vector<int> Solution::slidingMaximum(const vector<int> &A, int B) {
    multiset<int> s;
    vector<int> v;
    
    int i = 0, j = 0;
    int n = A.size();
    
    while(j < n){
        s.insert(A[j]);
        
        if(j-i+1 < B)
            j++;        
        else if(j-i+1 == B){
            auto ele = --s.end();
            v.push_back(*ele);
            auto it = s.find(A[i]);
            
            if(it != s.end())
                s.erase(it);
            
            i++;
            j++;
        }
    }
    
    return v;
}
