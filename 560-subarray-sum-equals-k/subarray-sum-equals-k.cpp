//check the hint
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int>prefix_sum(n);
        prefix_sum[0]=nums[0];
        for(int i=1;i<n;i++){
            prefix_sum[i]=prefix_sum[i-1]+nums[i];
        }
        int res=0;
        unordered_map<int,int>mp;
        //corner case
        mp[0]=1;
        for(int i=0;i<n;i++){
            int val=prefix_sum[i]-k;
            res+=mp[val];
            mp[prefix_sum[i]]++;
        }
        return res;
    }
};