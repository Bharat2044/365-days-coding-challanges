// Question Link: https://www.interviewbit.com/problems/simplify-directory-path/

/*
Simplify Directory Path

Problem Description:
Given a string A representing an absolute path for a file (Unix-style).

Return the string A after simplifying the absolute path.

Note:
In Unix-style file system:
A period '.' refers to the current directory.
A double period '..' refers to the directory up a level.
Any multiple consecutive slashes '//' are treated as a single slash '/'.
In Simplified Absolute path:
The path starts with a single slash '/'.
Any two directories are separated by a single slash '/'.
The path doesn't end with trailing slashes '/'.
The path only contains the directories on the path from the root directory to the target file or directory (i.e., no period '.' or double period '..')
The path will not have whitespace characters.

Problem Constraints:
1 <= |A| <= 106

Input Format:
The only argument given is string A.

Output Format:
Return a string denoting the simplified absolute path for a file (Unix-style).

Example Input:
Input 1:
A = "/home/"
Input 2:
A = "/a/./b/../../c/"

Example Output:
Output 1:
"/home"
Output 2:
"/c"
 */



string Solution::simplifyPath(string A) {
    stack<char> s;

    int count =0;
    char B[A.size()];
    int j=0,i=0;
    while(i<A.size())
    {
        if(A[i]=='.')
        {
            if(A[i+1]=='.')
            {
                B[j++]='@';
                count++;
                i++;
            }
            else
            {
                i++;
                continue;
            }
        }
        else if(A[i]=='/' && B[j-1]=='/')
        {
            i++;
            continue;
        }
        else
        {
            B[j]=A[i];
            j++;
        }
        i++;
    }
   
    i=0;
    while(i<j)
    {
        if(B[i]=='@')
        {
            s.pop();
            if(s.empty())
                s.push('/');
            else
            {
                while(s.top()!='/')
                {
                    if(!s.empty())
                        s.pop();
                    else
                        s.push('/');
                }
                s.pop();
            }
        }
        else
            s.push(B[i]);
    i++;
    }
    if(s.top()=='/'&& s.size()>1)
        s.pop();
    string ans = "";
   while(!s.empty())
    {
        ans.push_back(s.top());
        s.pop();
    }
    int n = ans.length();
    if(ans[n-1]=='/' && ans[n-2]=='/')
        ans.pop_back();
    reverse(ans.begin(),ans.end());
    return ans;
}
