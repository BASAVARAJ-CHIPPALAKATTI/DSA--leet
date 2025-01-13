// 
class Solution {
public:
    int minimumLength(string s) {
        vector<int>freq(26,0);
        for(int i=0;i<s.size();i++){
            freq[s[i]-'a']++;
        }
        int count=0;
        for(int i=0;i<26;i++){
             if(freq[i]>=3){
                if(freq[i]%2==0){
                    count+=freq[i]-2;
                }
                else{
                    count+=freq[i]-1;
                }
             }
        }
        return s.size()-count;
    }
};