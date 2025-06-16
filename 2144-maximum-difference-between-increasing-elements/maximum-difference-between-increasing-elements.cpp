class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        int ans=-1;
        int minval=nums[0];
        for(int i=1;i<nums.size();i++){
            if(nums[i] <= minval){
                minval=nums[i];
            }
            else{
                ans=max(ans,nums[i]-minval);
            }
        }
        return ans;
    }
};