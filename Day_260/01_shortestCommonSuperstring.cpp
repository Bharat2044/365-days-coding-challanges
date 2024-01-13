// Question Link: https://www.interviewbit.com/problems/shortest-common-superstring/

/*
Shortest common superstring

Problem Description:
Given a set of strings, A of length N.
Return the length of the smallest string which has all the strings in the set as substrings.

Problem Constraints:
1 <= N <= 18
1 <= A[i] <= 100

Input Format:
The first and the only argument has an array of strings, A.

Output Format:
Return an integer representing the minimum possible length of the resulting string.

Example Input:
Input 1:
A = ["aaaa", "aa"]
Input 2:
A = ["abcd", "cdef", "fgh", "de"]

Example Output:
Output 1:
4
Output 2:
8

Example Explanation:
Explanation 1:
Shortest string: "aaaa"
Explanation 2:
Shortest string: "abcdefgh"
*/



int findOverlappingPair(string str1, string str2, string &str)
{
    // max will store maximum overlap i.e maximum
    // length of the matching prefix and suffix
    int max = INT_MIN;
    int len1 = str1.length();
    int len2 = str2.length();

    // check suffix of str1 matches with prefix of str2
    for (int i = 1; i <= min(len1, len2); i++)
    {
        // compare last i characters in str1 with first i
        // characters in str2
        if (str1.compare(len1-i, i, str2, 0, i) == 0)
        {
            if (max < i)
            {
                //update max and str
                max = i;
                str = str1 + str2.substr(i);
            }
        }
    }

    // check prefix of str1 matches with suffix of str2
    for (int i = 1; i <= min(len1, len2); i++)
    {
        // compare first i characters in str1 with last i
        // characters in str2
        if (str1.compare(0, i, str2, len2-i, i) == 0)
        {
            if (max <= i)
            {
                //update max and str
                max = i;
                str = str2 + str1.substr(i);
            }
        }
    }

    return max;
}

int Solution::solve(vector<string> &a) {
        int n=a.size(),len=n,max;
        while(len>1){
            max=INT_MIN;
            int l,r;
            string resstr;
            for(int i=0;i<len;i++){
                for(int j=i+1;j<len;j++){
                    string str;
                    int res = findOverlappingPair(a[i], a[j], str);
                    if(max<res){
                            max=res;
                            l=i;r=j;
                            resstr=str;
                        }
                    }
                }
            if(max==INT_MIN){
                a[0]+=a[len-1];
            }
            else{
                    a[l]=resstr;
                    a[r]=a[len-1];
                }
            len--;
        }
        
        return a[0].size();
}
