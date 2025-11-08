class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string>ans;
        string currans="";
        solve(currans,ans,n,n);
        return ans;
    }
    void solve(string currans,vector<string>&ans,int open,int close){
        if(close <= 0){              
            ans.push_back(currans);
        }
        if(open >0){
            currans.push_back('(');
            solve(currans,ans,open-1,close);
            currans.pop_back();
        }
        if(open < close){
            currans.push_back(')');
            solve(currans,ans,open,close-1);
            currans.pop_back();
        }
    }
};