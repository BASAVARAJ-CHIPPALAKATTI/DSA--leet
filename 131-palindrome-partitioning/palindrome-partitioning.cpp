class Solution {
public:
   int n;
    vector<vector<string>> partition(string s) {
        vector<vector<string>>ans;
        vector<string> currans;
        n=s.size();
        solve(0,s,currans,ans);
        return ans;
    }
    void solve(int idx,string s,vector<string>currans, vector<vector<string>>&ans){
        if(idx == n){
            ans.push_back(currans);
            return ;
        }
        for(int i=idx;i<n;i++){
            if(ispalindrome(s,idx,i)){
                currans.push_back(s.substr(idx ,i-idx+1));
                solve(i+1,s,currans,ans);
                currans.pop_back();
            }
        }
    }
    bool ispalindrome(string &s,int i,int j){
        while(i <=j){
            if(s[i]!=s[j]){
                return false;
            }
            i++;
            j--;
        }
        return true;
    }
};