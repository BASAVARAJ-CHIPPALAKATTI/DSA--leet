class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int ans=INT_MIN;
        int currans=-1001;
        for(int num : nums){
            currans=max(currans+num ,num);
            ans=max(currans,ans);
        }
        return ans;
    }
};