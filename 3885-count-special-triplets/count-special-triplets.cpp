
class Solution {
public:
    int  M = 1e9+7;
    int specialTriplets(vector<int>& nums) {
        int res=0;
        unordered_map<int,int>prev_freq;
        unordered_map<int,int>next_freq;
        for(int i=0;i<nums.size();i++){
            next_freq[nums[i]]++;
        }
        for(int i=0;i<nums.size();i++){
            next_freq[nums[i]]--;
            int j=nums[i]*2;
            int left=prev_freq[j];
            int right=next_freq[j];

            res=(res+(1LL*left*right))%M;
            prev_freq[nums[i]]++;
            
        }
        return res;
    }
};