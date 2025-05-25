class Solution {
public:
    int longestPalindrome(vector<string>& words) {
       int res=0;
       unordered_map<string,int>mp;
       for( string word : words){
           string revword=word;
           reverse(revword.begin(),revword.end());
           if(mp[revword]>0){
            res+=4;
            mp[revword]--;
           }
           else{
            mp[word]++;
           }
       }
       for(auto &it :  mp){
           string word=it.first;
           int freq=it.second;
           if(word[0]==word[1] && freq>0){
            res+=2;
            break;
           }
       }
       return res;
    }
};