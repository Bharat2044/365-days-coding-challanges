// Question Link: https://www.interviewbit.com/problems/order-of-people-heights/

/*
Order of People Heights

You are given the following :
A positive number N
Heights : A list of heights of N persons standing in a queue
Infronts : A list of numbers corresponding to each person (P) that gives the number of persons who are taller than P and standing in front of P
You need to return  list of actual order of persons’s height

Consider that heights will be unique

Example
Input : 
Heights: 5 3 2 6 1 4
InFronts: 0 1 2 0 3 2
Output : 
actual order is: 5 3 2 1 6 4 

So, you can see that for the person with height 5, there is no one taller than him who is in front of him, and hence Infronts has 0 for him.
For person with height 3, there is 1 person ( Height : 5 ) in front of him who is taller than him.
You can do similar inference for other people in the list.
*/



vector<int> Solution::order(vector<int> &A, vector<int> &B) {
   
    int n = A.size();
    vector<pair<int, int>> v;
    for(int i=0; i<A.size(); i++){
        v.push_back({A[i], B[i]});
    }
    //sort on acsending order of A
    sort(v.begin(), v.end());
   
    vector<int> ans(n, -1);
   
    for(int i=0; i<n; i++){
        int cnt=0, j;
        for(j=0; j<n; j++){
            if(cnt == v[i].second)break;
            if(ans[j] == -1)cnt++;
        }
        while(ans[j]!=-1)j++;
        ans[j] = v[i].first;
    }
    return ans;
}
