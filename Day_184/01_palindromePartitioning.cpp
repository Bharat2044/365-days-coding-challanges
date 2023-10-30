// Question Link: https://www.interviewbit.com/problems/palindrome-partitioning/

/*
Palindrome Partitioning

Given a string s, partition s such that every string of the partition is a palindrome.

Return all possible palindrome partitioning of s.

For example, given s = "aab",

Return
  [
    ["a","a","b"]
    ["aa","b"],
  ]
Ordering the results in the answer :

Entry i will come before Entry j if :

len(Entryi[0]) < len(Entryj[0]) OR
(len(Entryi[0]) == len(Entryj[0]) AND len(Entryi[1]) < len(Entryj[1])) OR
*
*
*
(len(Entryi[0]) == len(Entryj[0]) AND … len(Entryi[k] < len(Entryj[k]))
In the given example,
   ["a", "a", "b"] comes before ["aa", "b"] because len("a") < len("aa")
*/



bool ispalindrome(string str)
{
    string str1=str;
    reverse(str1.begin(),str1.end());
    if(str1==str) return true;
    else return false;
}

bool ispalindromev(vector<string>&ans1)
{
    for(int i=0; i<ans1.size(); i++)
    {
        if(ispalindrome(ans1[i])) continue;
        else return false;
    }
    return true;
}


bool palindrome(vector<vector<string>>&ans, string &str, string &A, int index, vector<string>&ans1)
{
    if(index==A.size())
    {
        if(ispalindromev(ans1))
        {
            ans.push_back(ans1);
            return true;
        }
       
        return false;
    }
    string str1;
    for(int i=index; i<A.size(); i++)
    {
        str1+=A[i];
        if(ispalindrome(str1))
        {
            ans1.push_back(str1);
            palindrome(ans,str,A,i+1,ans1);
            ans1.pop_back();
        }    
    }
   
    return true;
}

vector<vector<string> > Solution::partition(string A) {
    vector<vector<string>> ans;
    vector<string>ans1;
    string str="";
    palindrome(ans,str,A,0,ans1);
   
    return ans;
}

