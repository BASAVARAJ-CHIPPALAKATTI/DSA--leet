class Solution {
public:
    vector<vector<int>>ans;
    set<vector<int>>st;
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<int>currans;
        solve(nums,0,currans);
        return ans;
    }
    void solve(vector<int>&nums,int i ,vector<int>currans){
        if(i==nums.size()){
            vector<int>arr =currans;
            sort(arr.begin(),arr.end());
            if(!st.count(arr)){
                ans.push_back(currans);
                st.insert(arr);
            }
            return;
        }
        solve(nums,i+1,currans);
        currans.push_back(nums[i]);
        solve(nums,i+1,currans);
        
    }

};