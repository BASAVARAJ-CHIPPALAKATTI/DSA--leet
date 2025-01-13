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
             while(freq[i]>2){
                freq[i]-=2;
                count+=2;
             }
        }
        return s.size()-count;
    }
};