// Question Link: https://www.interviewbit.com/problems/count-element-occurence/

/*
Count Element Occurence

Given a sorted array of integers, find the number of occurrences of a given target value.

Your algorithm’s runtime complexity must be in the order of O(log n).
If the target is not found in the array, return 0

Example : 
Given [5, 7, 7, 8, 8, 10] and target value 8,
return 2.
*/



int firstOccuernces(const vector<int> &A, int B) {
    int n = A.size();
    int l = 0;
    int h = n-1;
    int ans = -1;

    while(l<=h) {
        int mid  = l + (h-l)/2;

        if (A[mid] == B) {
            ans = mid;
            h = mid - 1;
        } 
        else if(A[mid] > B) 
            h  = mid - 1;
        else 
            l = mid + 1;
    }

    return ans;
}

int lastOccuernces(const vector<int> &A, int B) {
    int n = A.size();
    int l = 0;
    int h = n-1;
    int ans = -1;

    while(l<=h) {
        int mid  = l + (h-l)/2;

        if (A[mid] == B) {
            ans = mid;
            l = mid + 1;
        } 
        else if(A[mid] > B) 
            h  = mid - 1;
        else 
            l = mid + 1;
    }
    
    return ans;
}

int Solution::findCount(const vector<int> &A, int B) {
    if(A.size() == 0) 
        return 0;

    //find firstOccuernce - logn
    int firstOccuerncesIdx = firstOccuernces(A, B);

    //key not found
    if(firstOccuerncesIdx == -1) 
        return 0;

    //find lastOccuernce - logn
    int lastOccuerncesIdx = lastOccuernces(A, B);

    return lastOccuerncesIdx - firstOccuerncesIdx + 1;
}
