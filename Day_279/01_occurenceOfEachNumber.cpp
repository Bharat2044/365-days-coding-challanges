// Question Link: https://www.interviewbit.com/problems/occurence-of-each-number/

/*
Occurence of Each Number

Problem Description:
You are given an integer array A.
You have to find the number of occurences of each number.
Return an array containing only the occurences with the smallest value's occurence first.
For example, A = [4, 3, 3], you have to return an array [2, 1], where 2 is the number of occurences for element 3, 
and 1 is the number of occurences for element 4. But, 2 comes first because 3 is smaller than 4.

Problem Constraints:
1 <= |A| <= 105
1 <= Ai <= 109

Input Format:
The first argument is the integer array A.

Output Format:
Return an integer array denoting the occurences of each number.

Example Input:
Input 1:
A = [1, 2, 3]
Input 2:
A = [4, 3, 3]

Example Output:
Output 1:
[1, 1, 1]
Output 2:
[2, 1]

Example Explanation:
Explanation 1:
All the elements occur once, so the resultant array should be [1, 1, 1].
Explanation 2:
Explained in the description above.
*/



vector<int> Solution::findOccurences(vector<int> &A) {
    vector<int> res;
    sort(A.begin(), A.end());
    
    res.push_back(0);
    int cur = A[0];
    
    for(int i=0; i<A.size(); i++){
        if(A[i] != cur) res.push_back(0), cur = A[i];
            res.back()++;
    }
    
    return res;
}
