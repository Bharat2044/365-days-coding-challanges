// Question Link: https://www.codechef.com/problems/HCAGMAM1


#include <iostream>
#include <string>
using namespace std;

int main()
{
    int t;
    cin >> t;
    
    while (t--)
    {
        int x, y;
        cin >> x >> y;
        
        string str;
        cin >> str;
        
        int wd = 0;
        int ls = 0;
        int max = 0;
        
        for (int i=0;i<30;i++){
            if(str[i]=='1'){
                wd++;
                max++;
                if(max>ls){
                    ls= max;
                }
            }
            else{
                max=0;
            }
        }
       
        int ans = (wd * x) + (ls * y);
        cout << ans << endl;
    }
    
    return 0;
}
