class Solution {
public:
    vector<string>ans;
    vector<string> validStrings(int n) {
        string curr="";
        solve(curr,n);
        return ans;
    }
    void solve(string curr,int n){
        if(curr.size()==n){
            ans.push_back(curr);
            return; 
        }
        if(curr.empty() || curr.back()=='1'){
            curr.push_back('0');
            solve(curr,n);
            curr.pop_back();
            curr.push_back('1');
            solve(curr,n);
        }
        else{
            curr.push_back('1');
            solve(curr,n);
        }
    }
};