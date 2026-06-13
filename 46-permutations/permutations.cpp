class Solution {
public:
    vector<vector<int>>ans;
    vector<vector<int>> permute(vector<int>& nums) {
        unordered_set<int>st;
        vector<int>currans;
        solve(nums,currans,st);
        return ans;
    }
    void solve(vector<int>& nums,vector<int>currans,unordered_set<int>st){
        if(currans.size()==nums.size()){
            ans.push_back(currans);
            return ;
        }
        for(int i=0;i<nums.size();i++){
            if(!st.count(nums[i])){
                currans.push_back(nums[i]);
                st.insert(nums[i]);
                solve(nums,currans,st);
                currans.pop_back();
                st.erase(nums[i]);
            }
        }
    }
};