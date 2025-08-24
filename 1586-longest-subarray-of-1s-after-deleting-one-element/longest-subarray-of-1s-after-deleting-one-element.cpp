class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int i=0;
        int j=0;
        int ans=0;
        int currans=0;
        int count_zero=0;
        while(j<nums.size()){
            if(nums[j]==1){
                currans++;
            }
            else{
                count_zero++;
            }
            while(count_zero >=2){
                if(nums[i]==1){
                    currans--;
                }
                else{
                    count_zero--;
                }
                i++;
            }
            if(count_zero==0){
                ans=max(ans,currans-1);
            }
            else{
                ans=max(ans,currans);
            }
            j++;
        }
        return ans;
    }
};