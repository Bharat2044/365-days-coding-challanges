// Question Link: https://www.interviewbit.com/problems/compare-version-numbers/

/*
Compare Version Numbers

Problem Description:
Compare two version numbers version1 and version2.
If version1 > version2 return 1,
If version1 < version2 return -1,
otherwise return 0.
You may assume that the version strings are non-empty and contain only digits and the . character.
The . character does not represent a decimal point and is used to separate number sequences. For instance, 2.5 is not "two and a half" or "half way to version three", it is the fifth second-level revision of the second first-level revision.

Note: Here is an example of version numbers ordering:
0.1 < 1.1 < 1.2 < 1.13 < 1.13.4

Problem Constraints:
1 <= |A|, |B| <= 5000

Input Format:
The first argument is a string A representing version1.
The first argument is a string B representing version2.

Output Format:
Return an integer.

Example Input:
A = "1.13"
B = "1.13.4"

Example Output:
-1

Example Explanation:
Version1 = "1.13"
Version2 = "1.13.4"
Version1 < version2, hence return -1
*/



int Solution::compareVersion(string s1, string s2) {
    int i=0 , j=0;

    if(s1==s2)
    {
        return 0;
    }
    
    while(i<s1.size() || j<s2.size())
    {
        string v1="" , v2="";

        while(i<s1.size() && s1[i]=='0')
        {
            i++;
        }

        while(i<s1.size() && s1[i]!='.')
        {
            v1+=s1[i];
            i++;
        }

           while(j<s2.size() && s2[j]=='0')
        {
            j++;
        }

        while(j<s2.size() && s2[j]!='.')
        {
            v2+=s2[j];
            j++;
        }

        if(v1.size()>v2.size())
        {
            return 1;
        }
        else
        if(v1.size()<v2.size())
        {
            return -1;
        }
        else{
            if(v1>v2)
            {
                return 1;
            }
            else
            {
                if(v1<v2)
                {
                    return -1;
                }
            }
        }
       
        if(i!=s1.size())
        {
            i++;
        }
        if(j!=s2.size())
        {
            j++;
        }
    }

    return 0;
}
