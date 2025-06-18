class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int i=0;
        vector<vector<int>>ans;
        while(i<nums.size()-2){
            if(abs(nums[i]-nums[i+2])>k){
                return {};
            }
            ans.push_back({nums[i],nums[i+1],nums[i+2]});
            i+=3;
        }
        return ans;
    }
};