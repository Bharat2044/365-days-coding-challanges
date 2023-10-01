// Question Link: https://www.interviewbit.com/problems/k-th-permutation/

/*
K-th Permutation

Problem Description:
You are given an integer A which represents the length of a permutation.
 A permutation is an array of length A where all the elements occur exactly once and in any order.
 For example, [3, 4, 1, 2], [1, 2, 3] are examples of valid permutations while [1, 2, 2], [2] are not.

You are also given an integer B.
 If all the permutation of length A are sorted lexicographically, return the Bth permutation.

Problem Constraints:
1 <= A <= 105
1 <= B <= min(1018, A!), where A! denotes the factorial of A.

Input Format:
The first argument is the integer A.
The second argument is the long integer B.

Output Format:
Return an array denoting the Bth permutation of length A.

Example Input:
Input 1:
A = 3
B = 3
Input 2:
A = 1
B = 1
 
Example Output:
Output 1:
[2, 1, 3]
Output 2:
[1]

Example Explanation:
Explanation 1:
All the permutations of length 3 sorted in lexicographical order are:
[1, 2, 3], [1, 3, 2], [2, 1, 3], [2, 3, 1], [3, 1, 2], [3, 2, 1].
Therefore, the third permutation is [2, 1, 3].
Explanation 2:
There is only one possible permutation -> [1].
*/



long long arr[21];

void precalc()
{
    arr[0] = 1;
    arr[1] = 1;
    for (int i = 2; i <= 20; i++)
    {
        arr[i] = arr[i - 1] * i;
    }
}

vector<int> Solution::findPerm(int A, long B)
{
    precalc();
    vector<int> ans;
    set<int> used;
    
    for (int i = 1; i <= A; i++)
    {
        used.insert(i);
    }
    
    for (int i = 1; i <= (A - 20); i++)
    {
        used.erase(i);
        ans.push_back(i);
    }
    
    int x;
    if(A > 20){
        x = 19;
    } else{
        x = A - 1;
    }

    while (used.empty() == false) {

        for (auto it = used.begin(); it != used.end(); it++)
        {
            if (B > arr[x])
            {
                B -= arr[x];
            }
            else
            {
                ans.push_back(*it);
                used.erase(*it);
                x--;
                break;
            }
        }
    }
    
    return ans;
}

