class Solution {
public:
   int t[301];
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string>st;
        for(string word : wordDict){
            st.insert(word);
        }
        memset(t,-1,sizeof(t));
        return solve(s,st,0);
    }
    bool solve(string s, unordered_set<string>&st ,int i){
        if(i==s.size()){
            return true;
        }
        if(t[i]!=-1){
            return t[i];
        }
        for(int j=i;j<s.size();j++){
            if(st.count(s.substr(i,j-i+1))){
                if(solve(s,st,j + 1)) {
                    return t[i] =true;
                }
            }
        }
        return t[i]=false;
    }
};