// Question Link: https://www.interviewbit.com/problems/justified-text/

/*
Justified Text

Problem Description:
Given an array of words and a length of L, format the text such that each line has exactly L characters and is fully (left and right) justified. You should pack your words in a greedy approach; that is, pack as many words as you can in each line.

Pad extra spaces ' ' when necessary so that each line has exactly L characters. Extra spaces between words should be distributed as evenly as possible. If the number of spaces on a line does not divide evenly between words, the empty slots on the left will be assigned more spaces than the slots on the right. For the last line of text, it should be left justified and no extra space is inserted between words.

Your program should return a list of strings, where each string represents a single line. 

Note: Each word is guaranteed not to exceed L in length.

Problem Constraints:
0 <= |A| <= 1000
0 <= B <= 5 * 104

Input Format:
The first argument is an array of strings A representing words.
The second argument is an integer B representing L.

Output Format:
Return a list of strings, where each string represents a single line.

Example Input:
A: ["This", "is", "an", "example", "of", "text", "justification."]
B: 16.

Example Output:
[
   "This    is    an",
   "example  of text",
   "justification.  "
]

Example Explanation:
Given words: ["This", "is", "an", "example", "of", "text", "justification."]
L: 16.
Return the formatted lines as:
[
   "This    is    an",
   "example  of text",
   "justification.  "
]
*/



string setting(vector<string>A,int last,int id,int B, int cnt){
    string temp = "";
    if(id==last){
        int left = B - A[id].length();
        temp += A[id];
        while(left--){
            temp += " ";
        }
        return temp;
    }
    int blocks = id-last;
    cnt -= blocks;
    int left = B-cnt;
    int ext = left%blocks;
    int curr = left/blocks;
    for(int i = last;i<=id;i++){
        temp += A[i];
        if(i!=id){
            for(int j = 0;j<curr;j++){
                temp += " ";
            }
            if(ext){
                temp += " ";
                ext--;
            }
        }
    }
    return temp;
}
vector<string> Solution::fullJustify(vector<string> &A, int B){
    int cnt = 0;
    int last = 0;
    vector<string>ans;
    string temp = "";
    int n = A.size();
    for(int i = 0;i<n;i++){
        cnt += A[i].length() + 1;
        temp += A[i] + " ";
        if(cnt-1==B){
            temp.pop_back();
            ans.push_back(temp);
            temp = "";
            cnt = 0;
            last = i+1;
        }else if(cnt-1>B){
            temp = setting(A,last,i-1,B,cnt-2-A[i].length());
            ans.push_back(temp);
            i--;
            temp = "";
            last = i+1;
            cnt = 0;
        }else
        if(i==n-1){
            while(cnt<B){
                temp += " ";
                cnt++;
            }
            ans.push_back(temp);
        }
    }
    return ans;
}
