// Question Link: https://www.interviewbit.com/problems/inversions/

/*
INVERSIONS

Problem Description:
Given an array A, count the number of inversions in the array.
Formally speaking, two elements A[i] and A[j] form an inversion if A[i] > A[j] and i < j

Example Input:
A : [2, 4, 1, 3, 5]

Example Output:
3

Example Explanation:
A : [2, 4, 1, 3, 5]
Output : 3
as the 3 inversions are (2, 1), (4, 1), (4, 3).
*/



int mergeSort(vector<int>&a, int s, int mid, int e){
    vector<int> temp;
    int ct=0,i=s,j=mid+1;
    while(i<=mid && j<=e){
        if(a[i]<=a[j]){
            temp.push_back(a[i]);
            i++;
        }
        else {
            temp.push_back(a[j]);
            j++;
            ct+=mid-i+1;  // count here
        }
    }
    while(j<=e) {
        temp.push_back(a[j++]);
    }
    while(i<=mid){
        temp.push_back(a[i++]);
    }
    for(int k=s; k<=e; k++){
        a[k]=temp[k-s];
    }
    return ct;
}

int merge(vector<int>&a, int s, int e){
    int ct=0;
    if(s>=e) return ct;
    int mid=(s+e)/2;
    ct+=merge(a,s,mid);
    ct+=merge(a,mid+1,e);
    ct+=mergeSort(a,s,mid,e);
    return ct;
}


int Solution::countInversions(vector<int> &a) {
    int ct=merge(a,0,a.size()-1);
    return ct;
}
