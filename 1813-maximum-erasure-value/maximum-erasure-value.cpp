class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        unordered_map<int,int>mp;
        int ans=0;
        int i=0;
        int j=0;
        int currans=0;
        while(j<nums.size()){
            currans+=nums[j];
            mp[nums[j]]++;
            while(mp[nums[j]] > 1){
                currans-=nums[i];
                mp[nums[i]]--;
                i++;
            }
            ans=max(ans,currans);
            j++;
        }
        return ans;
    }
};