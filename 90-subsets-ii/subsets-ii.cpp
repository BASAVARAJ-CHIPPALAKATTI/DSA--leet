class Solution {
public:
    vector<vector<int>>ans;
    set<vector<int>>st;
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<int>currans;
        sort(nums.begin(),nums.end());
        solve(nums,0,currans);
        return ans;
    }
    void solve(vector<int>&nums,int i ,vector<int>currans){
        if(i==nums.size()){
            // vector<int>arr =currans;
            // sort(arr.begin(),arr.end());
            if(!st.count(currans)){
                ans.push_back(currans);
                st.insert(currans);
            }
            return;
        }
        solve(nums,i+1,currans);
        currans.push_back(nums[i]);
        solve(nums,i+1,currans);
        
    }

};