class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int maxsum=nums[0];
        int minsum=nums[0];
        int currmaxsum=nums[0];
        int currminsum=nums[0];
        for(int i=1;i<nums.size();i++){
            currmaxsum=max(currmaxsum+nums[i] , nums[i]);
            currminsum=min(currminsum+nums[i] , nums[i]);


            maxsum=max(maxsum,currmaxsum);
            minsum=min(minsum,currminsum);
        }
        return max( maxsum , abs(minsum));
    }
};