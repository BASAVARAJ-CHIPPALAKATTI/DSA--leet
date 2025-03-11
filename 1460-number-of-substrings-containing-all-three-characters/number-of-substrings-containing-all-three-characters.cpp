class Solution {
public:
    int numberOfSubstrings(string s) {
        int res=0;
        int i=0;
        int j=0;
        unordered_map<int ,int>mp;
        while(j<s.size()){
            char c=s[j];
            mp[c-'a']++;
            while(mp[0]>0 && mp[1]>0 && mp[2]>0){
                res+=s.size()-j;
                mp[s[i]-'a']--;
                i++;
            }
            j++;
        }
        return res;
    }
};