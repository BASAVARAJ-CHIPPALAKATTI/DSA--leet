class Solution {
public:
    vector<vector<int>> ans;
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int>currans;
        set<int>st;
        solve(currans,st,nums);
        return ans;
    }
    void solve(vector<int>&currans,set<int>&st,vector<int>&nums){
        if(currans.size()==nums.size()){
            ans.push_back(currans);
            return ;
        }
        for(int i=0;i<nums.size();i++){
            if(st.count(nums[i])){
                continue;
            }
            currans.push_back(nums[i]);
            st.insert(nums[i]);
            solve(currans,st,nums);
            currans.pop_back();
            st.erase(nums[i]);
        }
    }
};