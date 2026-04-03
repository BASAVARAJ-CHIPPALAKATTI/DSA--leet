class Solution {
public:
    unordered_map<int,vector<char>>mp={ 
    {2,{'a','b','c'}}, 
    {3,{'d','e','f'}},
    {4,{'g','h','i'}},
    {5,{'j','k','l'}},
    {6,{'m','n','o'}},
    {7,{'p','q','r','s'}},
    {8,{'t','u','v'}},
    {9,{'w','x','y','z'}} };

    vector<string>ans;

    vector<string> letterCombinations(string digits) {
        solve(digits,0,"");
        return ans;
    }

    void solve(string digits,int i,string currans){
        if(currans.size()==digits.size()){
            ans.push_back(currans);
            return;
        }
        vector<char>ch = mp[digits[i]-'0'];
        for( char c : ch){
            currans.push_back(c);
            solve(digits,i+1,currans);
            currans.pop_back();
        }

    }
};