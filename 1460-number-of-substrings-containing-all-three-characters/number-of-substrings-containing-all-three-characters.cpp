class Solution {
public:
    int numberOfSubstrings(string s) {
        vector<int>find(3,0);
        int i=0;
        int j=0;
        int ans=0;
        while(j<s.size()){
            find[s[j]-'a']++;
            while(find[0] && find[1] && find[2]){
                ans+=s.size()-j;
                find[s[i]-'a']--;
                i++;
            }
            j++;
        }
        return ans;
    }
};