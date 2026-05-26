class Solution {
public:
    vector<string>ans;
    vector<string> generateParenthesis(int n) {
        solve(0,0,n,"");
        return ans;
    }
    void solve(int open,int close,int n,string currans){
        if(close == n){
            ans.push_back(currans);
            return ;
        }
        if(open <n){
            currans.push_back('(');
            solve(open+1,close,n,currans);
            currans.pop_back();
        }
        if(close < open){
            currans.push_back(')');
            solve(open,close+1,n,currans);
        }

    }
};