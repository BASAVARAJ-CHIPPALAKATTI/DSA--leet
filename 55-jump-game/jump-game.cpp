class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n=nums.size();
        int reachable=nums.size()-1;
        for(int i=n-2;i>=0;i--){
            if(nums[i]+i >= reachable){
                reachable=i;
            }
        }
        return reachable==0;
    }
};