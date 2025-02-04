class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        int result=0;
        int currres=nums[0];
        for(int i=1;i<nums.size();i++){
            if(nums[i-1]<nums[i]){
                currres+=nums[i];
            }
            else{
                result=max(result,currres);
                currres=nums[i];
            }
        }
        result=max(result,currres);
        return result;
    }
};