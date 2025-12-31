class Solution {
public:
    int t[51];
    int minExtraChar(string s, vector<string>& dictionary) {
        unordered_set<string>st;
        for(string &dict : dictionary){
            st.insert(dict);
        }
        memset(t,-1,sizeof(t));
        return solve(0,s,st);
    }
    int solve(int idx,string s,unordered_set<string>&st){
        if(idx >= s.size()){
            return 0;
        }
        if(t[idx]!=-1){
            return t[idx];
        }
        int res=1+solve(idx+1,s,st);
        for(int j=idx;j<s.size();j++){
            string curr=s.substr(idx,j-idx+1);
            if(st.count(curr)){
                res=min(res,solve(j+1,s,st));
            }
        }
        return t[idx]=res;
    }
};