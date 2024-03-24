// Question Link: https://www.interviewbit.com/problems/anagram-match/

/*
Anagram Match

Problem Description:
You are given a string A. You need to solve Q queries. In each query, you will be given a string B[i]. You need to find the count of the number of substrings of A which are anagrams of B[i]. 
String x is an anagram of string y, if we can rearrange the letters in string x and get the exact string y. For example, strings "dog" and "god" are anagrams, so are strings "baba" and "aabb", but strings "abbac"  "caaba" are not.
A substring of a string is a contiguous subsequence of that string. So, string "view" is substring of string "interviewbit", but string "viewer" is not.

Problem Constraints:
1 <= |A|, |B[i]| <= 2 x 10^5
1 <= Q <= 10^5
∑ |B[i]| <= 2 x 10^5
All the strings consist of lowercase english letters.

Input Format:
The first argument contains a string A.
The second argument contains an array of strings B.

Output Format:
Return an array of size Q, i-th integer is the number of substrings of A which are anagrams of B[i].

Example Input:
Input 1:
  A : "jdlidfa"
  B : [ "daf", "ifd", "dxzjbltsmufythgm" ]
Input 2:
  A : "lrprpqejhh"
  B : [ "p", "pjeplqrr"] 

Example Output:
Output 1:
  [1, 1, 0]
Output 2:
  [2, 1]

Example Explanation:
Explanation 1:
  1. Substring  "dfa" is an anagram of "daf".
  2. Substring "idf" is an anagram of "ifd"
  3. No anagram exists as a substring.
Explanation 2:
  1. Substring "p" occurs twice in A.
  2. Substring "lrprpqej" is an anagram of "pjeplqrr".
*/



int p[26] = {130651,169627,95789,197101,104803,176509,113909,172597,6221,86269,188999,166867,4271,177787,172709,79151,155153,40897,156781,26459,176087,86243,164309,40597,181397,39791};
string s, t[100005];
int q, ans[100005];
long long hashh[200005];
vector<int> Solution::solve(string A, vector<string> &B) {
    s = A;
    q = B.size();
    for(int i = 0; i < s.size(); i++)
        hashh[i] = (i ? hashh[i-1] : 0) + p[s[i]-'a'];
    unordered_map<int, vector< pair < long long, int >>> hashh_m;
    for(int i = 0; i < q; i++){
        t[i] = B[i];
        long long hashh_t = 0;
        for(char j:t[i])
            hashh_t += p[j-'a'];
        hashh_m[t[i].size()].push_back({hashh_t, i});
    }
    for(auto i:hashh_m){
        vector<pair <long long, int >> hashh_l = i.second;
        unordered_map<long long, int> count_m;
        for(auto j:hashh_l)
            count_m[j.first] = 0;
        int l = i.first;
        for(int j = 0; j < int(s.size())-l+1; j++){
            long long hashh_s = hashh[j+l-1] - (j ? hashh[j-1] : 0);
            if(count_m.count(hashh_s))
                count_m[hashh_s]++;
        }
        for(auto j:hashh_l)
            ans[j.second] = count_m[j.first];
    }
    vector<int>res;
    for(int i = 0; i < q; i++)
        res.push_back(ans[i]);
    return res;
}
