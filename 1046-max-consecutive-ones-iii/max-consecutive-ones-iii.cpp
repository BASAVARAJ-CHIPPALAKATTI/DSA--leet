//own
class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int ans=0;
        int i=0;
        int j=0;
        int count_zero=0;
        while(j<nums.size()){
            if(nums[j]==0){
                count_zero++;
            } 
            if(count_zero<=k){
                ans=max(ans,j-i+1);
            }
            while(count_zero > k){
                if(nums[i]==0){
                    count_zero--;
                }
                i++;
            }
            j++;
        }
        return ans;
    }
};