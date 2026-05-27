//
class Solution {
public:
    int numberOfSpecialChars(string word) {
        vector<int>upper(26,-1);
        vector<int>lower(26,-1);

        for(int i=0;i<word.size();i++){
            if(word[i] >= 'A' && word[i] <='Z'){
                continue;
            }
            else{
                lower[word[i]-'a']=i;
            }
        }
        for(int i=word.size()-1;i>=0;i--){
            if(word[i] >= 'A' && word[i] <='Z'){
                upper[word[i]-'A']=i;
            }
            else{
                continue;
            }
        }
        int ans=0;
        for(int i=0;i<26;i++){
            if(upper[i]!=-1 && lower[i]!=-1){
                if(lower[i] < upper[i]){
                    ans++;
                }
            }
        }
        return ans;
    }
};