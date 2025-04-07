//own
class Solution {
public:
    int t[201][20001];
    bool canPartition(vector<int>& nums) {
        int totalsum=0;
        for(int i=0;i<nums.size();i++){
            totalsum+=nums[i];
        }
        // we need to find there is one subset(atleast one elt or
        // atmost n-1 elts) that is equal to totalsum/2
        if(totalsum%2!=0) return false;
        
        memset(t,-1,sizeof(t));
        return solve(nums,0,0,totalsum/2);
    }
    bool solve(vector<int>&nums,int sum ,int idx,int target){
        if(sum==target){
            return true;
        }
        if(t[idx][sum]!=-1){
            return t[idx][sum];
        }
        if(sum > target || idx >= nums.size()){
            return false;
        }
        
        bool take=solve(nums,sum+nums[idx],idx+1,target);
        bool nottake=solve(nums,sum,idx+1,target);
        
        return t[idx][sum]= (take || nottake);
        
    }
};