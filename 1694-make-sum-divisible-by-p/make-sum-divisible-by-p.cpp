class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        int target=0;
        for(int num : nums){
            target=(target+num)%p;
        }
        if(target==0){
            return 0;
        }
        //it is like prefix sum finding curr prev one
        int res=nums.size();
        int curr=0;
        unordered_map<int,int>mp;
        mp[0]=-1;
        for(int i=0;i<nums.size();i++){
            curr=(curr+nums[i])%p;
            int prev=(curr-target+p)%p; // +p to avoid -ve integer
            if(mp.count(prev)){
                res=min(res,i-mp[prev]);
            }
            mp[curr]=i;
        }
        return( res==nums.size())?-1: res;
    }
};