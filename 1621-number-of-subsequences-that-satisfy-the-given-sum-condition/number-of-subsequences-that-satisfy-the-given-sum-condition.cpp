class Solution {
public:
    int numSubseq(vector<int>& nums, int target) {
        int m=1e9+7;
        sort(nums.begin(),nums.end());
        int l=0;
        int h=nums.size()-1;
        int res=0;
        vector<int>power(nums.size(),1);
        for(int i=1;i<nums.size();i++){
            power[i]=(power[i-1]*2)%m;
        }
        while(l<=h){
            if((nums[l]+nums[h])<=target){
                res=(res %m+power[h-l])%m;
                l++;
            }else{
                h--;
            }
        }
        return res%m;
    }
};