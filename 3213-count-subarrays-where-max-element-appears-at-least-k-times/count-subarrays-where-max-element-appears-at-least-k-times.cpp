class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        int maxelt=nums[0];
        for(int num : nums){
            maxelt=max(maxelt,num);
        }
        long long countSubA=0;
        int countMaxelt=0;
        int i=0;
        int j=0;
        int n=nums.size();
        while(j<n){
            if(nums[j]==maxelt){
                countMaxelt++;
            }
            while(countMaxelt>=k){
                countSubA+=n-j;
                if(nums[i]==maxelt){
                    countMaxelt--;
                }
                i++;
            }
            j++;
        }
        return countSubA;
    }
};