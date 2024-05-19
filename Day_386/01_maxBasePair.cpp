// Question Link: https://www.interviewbit.com/problems/max-base-pair/

/*
Max Base Pair

Problem Description:
You are given an integer array A. There is a function,F for two integers X and Y with another variable B(base).
Now for caluculating the functional value first convert X and Y in Base B and then ith bit of F(X,Y,B) = (Xi+Yi)%B.
You have to return the maximum functional value possible for any pair of elements of Array A in base B. Please note that you can't take two elements for pair from the same index.

NOTE: Array elements are in base 10 and you have to return your answer also in base 10(calculated value from equation is in base B).

Problem Constraints:
1 <= A.size() <= 10^6
2 <= A[i] <= 10^6
2 <= B <= 9

Input Format:
First argument is a vector of integers A.
Second argument is an integer B

Output Format:
Return a single integer showing maximum pair functional value.

Example Input:
Input 1:
10 1 2 3 4 5 6 7 8 9 10
3
Input 2:
5 10 99 88 48 213
7

Example Output:
Output 1:
19
Output 2:
312

Example Explanation:
Explanation 1:
93 = 100 and 103 = 101
Hence, F(9,10,3) = 2013 = 1910
We may check for other pairs we will get less than or equal to 15.
Explanation 2:
Lets calculate F(i,j,7) for all pairs,
10 99: 109
10 88: 91
10 48: 2
10 213: 223
99 88: 187
99 48: 140
99 213: 312
88 48: 80
88 213: 245
48 213: 205
Clearly maximum value is 312.
*/


int b = 10, num_length = 21;

vector <int> num_to_vec_base(int x){
    vector <int> v;
    while(x > 0){
        v.push_back(x % b);
        x = x / b;
    }
    while(v.size() < num_length) v.push_back(0);
    reverse(v.begin(), v.end());
    return v;
}

int vec_to_num_base(vector <int> v){
    int val = 1, total = 0;
    for(int i = v.size()-1; i >= 0; i--){
        total += v[i] * val;
        val = val * b; 
    }
    return total;
}

struct trie_node{
    trie_node * next[21];
    int end_here = 0;
    trie_node(){
        for(int i = 0; i < 21; i++)next[i] = NULL;
    }
}; 

void insert(trie_node * cur, int ptr, vector <int> &num){
    if(ptr == num.size()) return;
    if(cur->next[num[ptr]] == NULL) cur->next[num[ptr]] = new trie_node;
    insert(cur->next[num[ptr]], ptr + 1, num);
}

vector <int> find(trie_node * cur, int ptr, vector<int> &num, vector <int> &built_ans){
    if(ptr >= num.size()) return built_ans;
    else{
        int number = num[ptr];
        for(int i = 0; i<b; i++){
            int modulo = (b-1 - number - i + 2 * b) % b;
            if(cur->next[modulo] != NULL){
                built_ans.push_back(modulo);
                return find(cur->next[modulo], ptr + 1, num, built_ans);
            }
        }
        cout << endl;
        return built_ans;
    }
}

vector <int> combine(vector <int> x, vector <int> y){
    for(int i = 0; i < x.size(); i++)x[i] = (x[i] + y[i]) % b;
    return x;
}

int Solution::solve(vector<int> &A, int B) {
    int n = A.size(), ans = 0;
    b=B;
	vector <vector<int>> vec;
    for(int i = 0; i<n; i++)vec.push_back(num_to_vec_base(A[i]));
    trie_node * root = new trie_node;
    insert(root,0,vec[0]);
    for(int i = 1; i < n; i++){
        vector <int> empty;
        vector <int> left = find(root,0,vec[i],empty);
        vector <int> ansvec = combine(vec[i],left);
        int cur_ans = vec_to_num_base(ansvec);
        if(cur_ans > ans)ans = cur_ans;
        insert(root,0,vec[i]);
    }
    return ans;
}

