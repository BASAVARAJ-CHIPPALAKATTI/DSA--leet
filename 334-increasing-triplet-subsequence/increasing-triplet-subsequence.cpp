class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int st_small=INT_MAX;
        int nd_small=INT_MAX;
        for(int i=0;i<nums.size();i++){
            if(nums[i] <= st_small){
                st_small=nums[i];
            }
            else if(nums[i] <= nd_small){
                nd_small=nums[i];
            }
            else{
                return true;
            }
        }
        return false;
    }
};