class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int ans=0;
        int i=0;
        int j=0;
        int count0=0;
        while(j<nums.size()){
            if(nums[j]==0){
                count0++;
            }
            if(count0 <=1){
                ans=max(ans,j-i+1);
            }
            while( count0>1){
                if(nums[i]==0){
                    count0--;
                }
                 i++;
            }
            j++;
        }
        return ans-1;
    }
};