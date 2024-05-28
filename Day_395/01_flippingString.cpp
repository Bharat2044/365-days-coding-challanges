// Question Link: https://www.interviewbit.com/problems/flipping-string/


int Solution::solve(string A) {
int n = A.size();
vector<int>consecutive_ones_front(n,0),consecutive_ones_back(n,0);
for(int i=0;i<n;i++){
if(A[i]==‘1’){
int ones = 1;
consecutive_ones_front[i] = ones;
int j = i + 1;
while(j<n && A[j]==‘1’){
ones++;
consecutive_ones_front[j] = ones;
j++;
}
i = j - 1;
}
else consecutive_ones_front[i] = 0;
}
for(int i=n-1;i>=0;i–){
if(A[i]==‘1’){
int ones = 1;
consecutive_ones_back[i] = ones;
int j = i - 1;
while(j>=0 && A[j]==‘1’){
ones++;
consecutive_ones_back[j] = ones;
j–;
}
i = j + 1;
}
else consecutive_ones_back[i] = 0;
}
int mx = 0;
for(int i=0;i<n;i++){
if(A[i]==‘0’){
int zeros = 1;
int j = i + 1;
while(j<n && A[j]==‘0’){
zeros++;
j++;
}
int prev_ones = 0, next_ones = 0;
if(i-1>=0) prev_ones = consecutive_ones_front[i-1];
if(j < n) next_ones = consecutive_ones_back[j];
mx = max(mx, prev_ones + zeros + next_ones);
i = j - 1;
}
}
return mx;
}
