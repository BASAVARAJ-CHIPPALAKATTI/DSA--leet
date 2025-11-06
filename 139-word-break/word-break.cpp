//revision
class Solution {
public:
    vector<int> t=vector<int>(301,-1);
    unordered_set<string>st;
    int n;
    bool wordBreak(string s, vector<string>& wordDict) {
        n=s.size();
        for( string word : wordDict){
            st.insert(word);
        }
        return solve(s,0);
    }
    bool solve(string s,int idx){
        if(idx==n){
            return true; // s is present in wordDict
        }
        if(st.count(s.substr(idx,n-idx))){
            return true;
        }
        if(t[idx]!=-1){
            return t[idx];
        }
        for(int i=1;i<=n;i++){
            if(st.count(s.substr(idx,i)) && solve(s,idx+i)){
                return t[idx]= true;
            }
        }
        return t[idx] =false;
    }
};