// Question Link: https://leetcode.com/problems/goat-latin/description/

/*
824. Goat Latin

You are given a string sentence that consist of words separated by spaces. Each word consists of lowercase and uppercase letters only.
We would like to convert the sentence to "Goat Latin" (a made-up language similar to Pig Latin.) The rules of Goat Latin are as follows:

If a word begins with a vowel ('a', 'e', 'i', 'o', or 'u'), append "ma" to the end of the word.
For example, the word "apple" becomes "applema".
If a word begins with a consonant (i.e., not a vowel), remove the first letter and append it to the end, then add "ma".
For example, the word "goat" becomes "oatgma".
Add one letter 'a' to the end of each word per its word index in the sentence, starting with 1.
For example, the first word gets "a" added to the end, the second word gets "aa" added to the end, and so on.
Return the final sentence representing the conversion from sentence to Goat Latin.

Example 1:
Input: sentence = "I speak Goat Latin"
Output: "Imaa peaksmaaa oatGmaaaa atinLmaaaaa"
Example 2:
Input: sentence = "The quick brown fox jumped over the lazy dog"
Output: "heTmaa uickqmaaa rownbmaaaa oxfmaaaaa umpedjmaaaaaa overmaaaaaaa hetmaaaaaaaa azylmaaaaaaaaa ogdmaaaaaaaaaa"
 
Constraints:
1 <= sentence.length <= 150
sentence consists of English letters and spaces.
sentence has no leading or trailing spaces.
All the words in sentence are separated by a single space.
*/



class Solution {
public:
    bool isValid(string &ans){
        if(ans[0]=='a' || ans[0]=='e' || ans[0]=='i' || ans[0]=='o' || ans[0]=='u' || ans[0]=='A' || ans[0]=='E' || ans[0]=='I' || ans[0]=='O' || ans[0]=='U') return true;
        return false;
    }
    string toGoatLatin(string sentence) {
        string val;
        vector<string>ans;
        for(int i=0; i<sentence.length(); i++){
            string temp;
            while(i<sentence.length() && sentence[i]!=' '){
                temp+=sentence[i];
                i++;
            }
            ans.push_back(temp);
        }
        string a1 = "a";
        for(int i=0; i<ans.size(); i++){
            if(isValid(ans[i])){
                val+=ans[i];
                val+="ma";
                val+=a1;
                a1+='a';
            }else{
                char a = ans[i][0];
                val+=ans[i].substr(1,ans[i].length()-1);
                val+=a;
                val+="ma";
                val+=a1;
                a1+='a';
        }
        if(i==ans.size()-1){
            return val;
        }else{
            val+=' ';
        }
        }
        return val;
    }
};
