//
//own
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int>freq(128,0);
        int i=0;
        int j=0;
        int len=0;
        while(j<s.size()){
            freq[s[j]]++;
                while(freq[s[j]]>1){
                    --freq[s[i]];
                    i++;
                }
            len=max(len,j-i+1);
            j++;
        }
        return len;
    }
};