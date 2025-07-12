class Solution {
public:
    vector<string>ans;
    string getHappyString(int n, int k) {
        string curr;
        solve(n,curr);
        if(ans.size() <k){
            return "";
        }
        return ans[k-1];
    }
    void solve(int n,string curr){
        if(curr.size()==n){
            ans.push_back(curr);
            return ;
        }
        for(int i='a';i<='c';i++){
            if(!curr.empty() && curr.back()==i){
                continue;
            }
            curr.push_back(i);
            solve(n,curr);
            curr.pop_back();
        }
    }
};