// Question Link: https://leetcode.com/problems/valid-word/description/

/*
3136. Valid Word

A word is considered valid if:
It contains a minimum of 3 characters.
It contains only digits (0-9), and English letters (uppercase and lowercase).
It includes at least one vowel.
It includes at least one consonant.
You are given a string word.
Return true if word is valid, otherwise, return false.

Notes:
'a', 'e', 'i', 'o', 'u', and their uppercases are vowels.
A consonant is an English letter that is not a vowel.

Example 1:
Input: word = "234Adas"
Output: true
Explanation:
This word satisfies the conditions.
Example 2:
Input: word = "b3"
Output: false
Explanation:
The length of this word is fewer than 3, and does not have a vowel.
Example 3:
Input: word = "a3$e"
Output: false

Explanation:
This word contains a '$' character and does not have a consonant.

Constraints:
1 <= word.length <= 20
word consists of English uppercase and lowercase letters, digits, '@', '#', and '$'.
*/



class Solution {
public:
    
    bool isvowel(char ch){
    if(ch=='A' || ch=='E' || ch=='I' || ch=='O' || ch=='U' 
      || ch=='a' || ch=='e' || ch=='i' || ch=='o' || ch=='u'){
        return true;
    }
    else{
        return false;
    }
}
    bool isValid(string word) {
        if(word.size()<3){
            return false;
        }
        int num=0;
        int v=0;
        int c=0;
        for(int i=0;i<word.size();i++){
            char ch=word[i];
            if(ch>='0' && ch<='9'){
                num++;
            }
            if((ch>='a' && ch<='z') || (ch>='A' && ch<='Z')){
            if(isvowel(ch)){
                v++;
            }
            else{
                c++;
            }
            }
           
        }
        if(num+v+c==word.size() && v>0 && c>0){
            return true;
        }
        return false;
    }
};
