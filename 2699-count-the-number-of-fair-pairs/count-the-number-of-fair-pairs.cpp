class Solution {
public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        long long res=0;
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size();i++){

            int xidx=lower_bound(nums.begin()+i+1,nums.end(),lower-nums[i])-nums.begin();
            int x=xidx-i+1;

            int yidx=upper_bound(nums.begin()+i+1 ,nums.end(),upper-nums[i])-nums.begin();
            int y=yidx-i+1;

            res+=y-x;

        }
        return res;
    }
};