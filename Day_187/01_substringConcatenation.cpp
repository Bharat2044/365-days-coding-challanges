// Question Link: https://www.interviewbit.com/problems/substring-concatenation/

/*
Substring Concatenation

You are given a string, S, and a list of words, L, that are all of the same length.

Find all starting indices of substring(s) in S that is a concatenation of each word in L exactly once and without any intervening characters.

Example :
S: "barfoothefoobarman"
L: ["foo", "bar"]
You should return the indices: [0,9].

(order does not matter).
*/




vector<int> Solution::findSubstring(string A, const vector<string> &B) {
    map<string,int>h1;
    vector<int>v;
    int n=0;
    int l=B[0].size();
    
    for(auto a:B){
        if(h1.find(a)==h1.end()){             
            h1[a]=1; n++; continue;
        }
        h1[a]++; n+=1;
     }
    for(int i=0;i<A.size();i++){
       if(h1.find(A.substr(i,l))!=h1.end()){
        map<string,int>h;
        
        h.insert(h1.begin(),h1.end());
        int f=i;
        int sum=0;
        
        while(h[A.substr(f,l)]>0){
            h[A.substr(f,l)]--;
            sum++;
            f+=l;
        }
        
        if(sum==n)v.push_back(i);
       }
    }
    
    return v;
}
