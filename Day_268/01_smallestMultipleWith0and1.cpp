// Question Link: https://www.interviewbit.com/problems/smallest-multiple-with-0-and-1/

/*
Smallest Multiple With 0 and 1

Problem Description:
You are given an integer A. You have to find the smallest multiple of A which consists of digits 0 and 1 only. Since this multiple could be large, return it in form of a string.
Note: Returned string should not contain leading zeroes.

Problem Constraints:
1 <= A <= 105

Input Format:
The first argument is an integer A.

Output Format:
Return a string equal to the smallest multiple of A which consists of digits 0 and 1 only

Example Input:
Input 1:
55
Input 2:
2

Example Output:
Output 1:
110
Output 2:
10

Example Explanation:
Explanation 1:
110 is the smallest integer which is divisible by 55 and contains 0 and 1 only
Explanation 2:
10 is the smallest integer which is divisible by 2 and contains 0 and 1 only
*/



string Solution::multiple(int A) {
    int n = A;
    if(n==1) return "1";

    /*here we are setting the size of vector as 'n' because the number of different
    types f remainders cannot be more than 'n'
    example : for n=7 all the possible remainders can be : 0,1,2,3,4,5,6*/
    vector<long long> dp(n);
    dp[1]=1;
   
    //this queue stores the remainder of string with A
    queue<int> bfs;
    //for string ="1" remainder will be 1%A == 1, therefore
    bfs.push(1);
    while(!bfs.empty()){
        int r = bfs.front();
        bfs.pop();
        if(r==0) {
            string s;
            while(dp[r]){// explaination at bottom
                s += '0' + dp[r]%2;
                dp[r] /= 2;
            }
            reverse(s.begin(), s.end());
            return s;
        }
       
        for(int digit : {0,1}/*formed an array of 0&1*/){
            int new_r = (10*r + digit) % n;
            if(dp[new_r]==0){
                bfs.push(new_r);
               
                /* Here we are soring the string int binary format as the string
                is made of 0's and 1's . Example if the string form is "10" then in binary it is equal to 2
                "11" is 3, "110" is 6. Therefore we are storing the binary value of string in vector dp*/
                dp[new_r] = dp[r]*2 + digit;
            }
        }
    }
    return "-1";  
}
