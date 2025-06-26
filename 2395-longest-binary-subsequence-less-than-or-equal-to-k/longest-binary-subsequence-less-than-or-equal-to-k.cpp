class Solution {
public:
    int longestSubsequence(string s, int k) {
        int len=0;
        long long powerval=1;
        for(int i=s.size()-1;i>=0;--i){
            if(s[i]=='0'){
                len++;
            }
            else if(k-powerval >=0){
                k-=powerval;
                len++;
            }
            if(powerval <= k){
                powerval <<=1;
            }
        }
        return len;
    }
};