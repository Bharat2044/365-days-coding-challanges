// Question Link: https://www.interviewbit.com/problems/next-permutation/

/*
Next Permutation
Programming
Arrays

Problem Description:
Implement the next permutation, which rearranges numbers into the numerically next greater permutation of numbers for a given array A of size N.

If such an arrangement is not possible, it must be rearranged in the lowest possible order i.e., sorted in ascending order.

Note:
The replacement must be in-place, do not allocate extra memory.
DO NOT USE LIBRARY FUNCTION FOR NEXT PERMUTATION. Use of Library functions will disqualify your submission retroactively and will give you penalty points.

Problem Constraints:
1 <= N <= 5e5
1 <= A[i] <= 1e9

Input Format:
The first and the only argument of input has an array of integers, A.

Output Format:
Return an array of integers, representing the next permutation of the given array.

Example Input:
Input 1:
    A = [1, 2, 3]
Input 2:
    A = [3, 2, 1]
Input 3:
    A = [1, 1, 5]
Input 4:
    A = [20, 50, 113]

Example Output:
Output 1:
    [1, 3, 2]
Output 2:
    [1, 2, 3]
Output 3:
    [1, 5, 1]
Output 4:
    [20, 113, 50]
*/




void swap(int *a, int *b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void reverseArr(int *A, int start, int end)
{
    int i = start, j = end, tmp;

    while(i < j)
    {
        tmp = A[i];
        A[i] = A[j];
        A[j] = tmp;
        i++; j--;
    }
}

/**
 * @input A : Integer array
 * @input n1 : Integer array's ( A ) length
 * 
 * @Output Integer array. You need to malloc memory, and fill the length in len1
 */
int* nextPermutation(int* A, int n1, int *len1) {
    int i;

    *len1 = n1;

    if(n1 < 2) return A;

    for(i = n1-1; i > 0; i--)
    {
        if(A[i] > A[i-1])
        {
            break;
        }
    }

    if(i != 0)
    {
        int j;
        for(j = n1-1; j >= i; j--)
        {
            if(A[i-1] < A[j])
            {
                swap(&A[j], &A[i-1]);
                break;
            }
        }

    }

    reverseArr(A, i, n1-1);

    return A;
}


