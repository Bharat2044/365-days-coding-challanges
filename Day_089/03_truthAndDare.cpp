// Question Link: https://www.codechef.com/problems/TRUEDARE


#include <bits/stdc++.h>
#define loop(N) for(int i=0;i<N;i++)
using namespace std;

int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--)
	{
	  int tr,dr,ts,ds,a;
	  set<int>t;
	  set<int>d;
	  cin>>tr;
	  loop(tr)
	  {
	    cin>>a;
	    t.insert(a);
	  }
	  cin>>dr;
	  loop(dr)
	  {
	    cin>>a;
	    d.insert(a);
	  }
	  int x=t.size();
	  int y=d.size();
	  cin>>ts;
	  loop(ts)
	  {
	    cin>>a;
	    t.insert(a);
	  }
	  cin>>ds;
	  loop(ds)
	  {
	    cin>>a;
	    d.insert(a);
	  }
	  
	  if(t.size()==x&&d.size()==y)
	    std::cout << "yes" << std::endl;
	  else
	    std::cout << "no" << std::endl;
	  
	}
	return 0;
}
