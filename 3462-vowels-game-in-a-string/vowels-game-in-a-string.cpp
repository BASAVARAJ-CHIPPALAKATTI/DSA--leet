//easy
// if count of vowels is odd or even
//alway win the alice only
// means if count of vowel atleast one also than only win the alice
class Solution {
public:
    bool doesAliceWin(string s) {
        for(int i=0;i<s.size();i++){
            if(isvowel(s[i])){
                return true;
            }
        }
        return false;
    }
    bool isvowel(char c){
        return (c=='a') || (c=='e') ||(c=='o') ||(c=='i') ||(c=='u') ;
    }
};