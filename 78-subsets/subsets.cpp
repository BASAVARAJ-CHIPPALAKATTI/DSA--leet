class Solution {
public:
    vector<vector<int>>ans;
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int>currans;
        solve(nums,0,currans);
        return ans;
    }
    void solve(vector<int>nums, int i,vector<int>currans){
        if(i==nums.size()){
            ans.push_back(currans);
            return;
        }
        //for take
        currans.push_back(nums[i]);
        solve(nums,i+1,currans);
        currans.pop_back();
        solve(nums,i+1,currans);
    }
};