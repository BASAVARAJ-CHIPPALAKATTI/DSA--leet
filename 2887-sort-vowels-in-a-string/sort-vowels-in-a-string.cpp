//easy
class Solution {
public:
    bool isvowel(char c){
        return (c=='a' )|| (c=='e' )|| (c=='i')||(c=='o')||(c=='u')||(c=='A' )||(c=='E') ||(c=='I')|| (c=='O') || (c=='U');
    }


    string sortVowels(string s) {
        vector<char>vow;
        for(int i=0;i<s.size();i++){
            if(isvowel(s[i])){
                vow.push_back(s[i]);
            }
        }
        int j=0;
        sort(vow.begin(),vow.end());
        for(int i=0;i<s.size();i++){
            if(isvowel(s[i])){
                s[i]=vow[j];
                j++;
            }
        }
        return s;
    }
    
};