// Question Link: https://www.interviewbit.com/problems/median-of-array/

/*
Median of Array

Problem Description:
There are two sorted arrays A and B of size m and n respectively.

Find the median of the two sorted arrays ( The median of the array formed by merging both arrays ).

The overall run time complexity should be O(log (m+n)).

NOTE: If the number of elements in the merged array is even, then the median is the average of n / 2 th and n/2 + 1th element. For example, if the array is [1 2 3 4], the median is (2 + 3) / 2.0 = 2.5 

Problem Constraints:
0 <= |A| <= 106
0 <= |B| <= 106
1 <= |A| + |B| <= 2 * 106

Input Format:
The first argument is an integer array A.
The second argument is an integer array B.

Output Format:
Return a double value equal to the median.

Example Input:
A : [1 4 5]
B : [2 3]

Example Output:
3

Example Explanation:
Merged A and B will be : [1, 2, 3, 4, 5]
Its median will be 3
*/



double  findMedian(const vector<int> &A,const vector<int> &B)
{
    int total = (A.size() + B.size());
    int half = (total+1)/2;
   
    int left = 0;
    int right = A.size();
   
    while(true)
    {
        int mid = (left + right)/2;
        int left1 = ((mid -1 >=0 and mid-1 <A.size())? A[mid-1]:INT_MIN);
        int left2 = (((half-mid-1)>=0 and half - mid -1 < B.size())?B[half -mid -1]:INT_MIN);
        int right1 = ((mid < A.size())?A[mid]:INT_MAX);
        int right2 = ((half -mid <B.size())?B[half - mid]:INT_MAX);
       
        if(left1 <= right2 and left2<=right1)
        {
            if(total%2 == 1)
            {
                double ans  = max(left1,left2);
                return ans;
            }
            else
            {
                double ans = ((double)max(left1,left2) + (double)min(right1,right2))/2;
                return ans;
            }
        }
        else if(left1 > right2)
            right = mid - 1;
        else if(left2 > right1)
            left = mid + 1;
    }
}

double Solution::findMedianSortedArrays(const vector<int> &A, const vector<int> &B) {
   if(A.size() <= B.size())
       return findMedian(A,B);   
   else   
       return findMedian(B,A);
}


