//same as house robber
//call fun(0,n-2)we need avoi last when we take oth index and fun(1,n-1)
class Solution {
public:
    int t[101];
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n==1){
            return nums[0];
        }
        // if(nums.size()==2){
        //     return max(nums[0],nums[1]);
        // }
        memset(t,-1,sizeof(t));
        int without_end_with_0=solve(0,n-1,nums);

        memset(t,-1,sizeof(t));
        int without_o_with_1=solve(1,n,nums);
        return max(without_end_with_0,without_o_with_1);
    }
    int solve(int i,int n,vector<int>&nums){
        if(i>=n){
            return 0;
        }
        if(t[i]!=-1){
            return t[i];
        }
        int taken=nums[i]+solve(i+2,n,nums);
        int nottaken=solve(i+1,n,nums);
        return t[i]= max(taken,nottaken);
    }
};