class Solution {
public:
    typedef long long LL;
    long long maximumTotalDamage(vector<int>& power) {
        int n=power.size();
        unordered_map<LL,LL>map;
        for(int i=0;i<n;i++){
            map[power[i]]++;
        }
        vector<LL>nums;
        for(auto it : map){
            nums.push_back(it.first);
        }
        sort(nums.begin(),nums.end());
        n=nums.size();
        vector<LL>dp(n,0);
        LL ans=INT_MIN;
        for(int i=n-1;i>=0;i--){
            long long not_take=(i+1) < n ? dp[i+1] : 0;
            int j=lower_bound(nums.begin()+i+1,nums.end(),nums[i]+3)-nums.begin();
            long long take=map[nums[i]]*nums[i]+( (j < n) ? dp[j] : 0);

            dp[i]=max(take,not_take);
            ans=max(dp[i],ans);
        }
        return ans;
    }
};