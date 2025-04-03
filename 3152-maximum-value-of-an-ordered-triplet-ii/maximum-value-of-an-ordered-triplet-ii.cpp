class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        long long ans=0;
        int maxdiff=0;
        int maxi=0;
        for(int i=0;i<nums.size();i++){
            ans=max(ans,(long long)maxdiff*nums[i]);    // find res
            maxdiff=max(maxdiff,maxi-nums[i]);  //find maxdiff
            maxi=max(maxi,nums[i]);   // find max i

        }
        return ans;
    }
};