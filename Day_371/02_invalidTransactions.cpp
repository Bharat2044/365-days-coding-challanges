// Question Link: https://leetcode.com/problems/invalid-transactions/

/*
1169. Invalid Transactions

A transaction is possibly invalid if:
the amount exceeds $1000, or;
if it occurs within (and including) 60 minutes of another transaction with the same name in a different city.
You are given an array of strings transaction where transactions[i] consists of comma-separated values representing the name, time (in minutes), amount, and city of the transaction.
Return a list of transactions that are possibly invalid. You may return the answer in any order.

Example 1:
Input: transactions = ["alice,20,800,mtv","alice,50,100,beijing"]
Output: ["alice,20,800,mtv","alice,50,100,beijing"]
Explanation: The first transaction is invalid because the second transaction occurs within a difference of 60 minutes, have the same name and is in a different city. Similarly the second one is invalid too.
Example 2:
Input: transactions = ["alice,20,800,mtv","alice,50,1200,mtv"]
Output: ["alice,50,1200,mtv"]
Example 3:
Input: transactions = ["alice,20,800,mtv","bob,50,1200,mtv"]
Output: ["bob,50,1200,mtv"]
 
Constraints:
transactions.length <= 1000
Each transactions[i] takes the form "{name},{time},{amount},{city}"
Each {name} and {city} consist of lowercase English letters, and have lengths between 1 and 10.
Each {time} consist of digits, and represent an integer between 0 and 1000.
Each {amount} consist of digits, and represent an integer between 0 and 2000.
*/



class details{
    public:
        string name, city;
        int time, money;
};

class Solution {
public:
    vector<string> invalidTransactions(vector<string>& transactions){
        int n=transactions.size();
        vector<details> info;
        vector<string> result;
        for(auto transaction : transactions){
            details d;
            string temp="";
            int counter=0;
            for(int i=0;i<transaction.size();i++){
                if(transaction[i]==','){
                    if(counter==0) d.name=temp;
                    else if(counter==1) d.time=stoi(temp);
                    else if(counter==2) d.money=stoi(temp);
                    temp="";
                    counter++;
                }else{
                    temp.push_back(transaction[i]);
                }
            }
            d.city=temp;
            info.push_back(d);
        }
        for(int i=0;i<info.size();i++){
            bool flag=false;
            if(info[i].money>1000){
                result.push_back(transactions[i]);
                continue;
            }
            for(int j=0;j<info.size();j++){
                if(i==j) continue;
                if(info[i].name==info[j].name and info[i].city!=info[j].city and abs(info[i].time-info[j].time)<=60){
                    flag=true;
                    break;
                } 
            }
            if(flag) result.push_back(transactions[i]);
        }
       
        return result;        
    }
};
